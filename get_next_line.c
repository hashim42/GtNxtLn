/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:23:53 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/04 02:11:14 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <stdio.h>

t_fd_buff	*get_curr_buff(t_fd_list **fd_list, int fd)
{
	t_fd_buff 	*curr_fd_buff;
	size_t		size;

	while (*fd_list)
	{
		curr_fd_buff = (t_fd_buff*)((*fd_list)->content);
		if (curr_fd_buff->fd == fd)
			return (curr_fd_buff);
		*fd_list = (*fd_list)->next;
	}
	curr_fd_buff = (t_fd_buff*)malloc(sizeof(t_fd_buff));
	if (curr_fd_buff)
	{
		curr_fd_buff->fd = fd;
		curr_fd_buff->lines = ft_strnew(BUFF_SIZE);
		if (!(curr_fd_buff->lines))
			return (NULL);
		curr_fd_buff->filend = 0;
		curr_fd_buff->len = 0;
		size = sizeof(curr_fd_buff);
		ft_lstadd(fd_list, ft_lstnew(curr_fd_buff, size));
	}
	return (curr_fd_buff);
}

int			set_fd_buff_lines(t_fd_buff *curr_fd_buff, char *buff)
{
	char	*tmp;

	tmp = curr_fd_buff->lines;
	curr_fd_buff->lines = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (ft_strichr(buff, 10));
}

int			read_from_file(t_fd_buff *curr_fd_buff)
{	
	char	*buff;
	int		ret;
	int		pos;

	if (curr_fd_buff->filend == 1)
		return (0);
	pos = -1;
	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(curr_fd_buff->fd, buff, BUFF_SIZE)) > 0 && pos < 0)
	{
		
		buff[ret] = '\0';
		pos = set_fd_buff_lines(curr_fd_buff, buff);
	}
	if (pos >= 0 && ret > 0)
		set_fd_buff_lines(curr_fd_buff, buff);
	curr_fd_buff->filend = (ret == 0) ? 1 : 0;
	curr_fd_buff->len = ft_strlen(curr_fd_buff->lines);
	return (1);
}

int			read_fd_buff(t_fd_buff *curr_fd_buff, char **line)
{
	int		pos;
	char	*tmp;
	char	*newline;
	char	*nextline;

	if (ft_strichr(curr_fd_buff->lines, 10) < 0)
		read_from_file(curr_fd_buff);
	ft_putstr(curr_fd_buff->lines);
	tmp = curr_fd_buff->lines;
	nextline = ft_strchr(curr_fd_buff->lines, 10);
	if (nextline)
		curr_fd_buff->lines = nextline + 1;
	pos = nextline ? nextline - tmp : ft_strlen(curr_fd_buff->lines);
	newline = ft_strsub(tmp, 0, pos);
	ft_strdel(&tmp);
	tmp = *line;
	*line = newline;
	ft_strdel(&tmp);
	return (ft_strlen(*line) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*fd_list;
	t_fd_buff			*curr_fd_buff;
	int					ret;

	curr_fd_buff = get_curr_buff(&fd_list, fd);
	if (!curr_fd_buff)
		return (-1);
	if ((ret = read_fd_buff(curr_fd_buff, line)) == 1)
		return (ret);
	if (ret == 0 && curr_fd_buff->filend == 1)
		return (0);
	return (1);
}
