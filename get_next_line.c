/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:23:53 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/10 02:11:56 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <stdio.h>

t_fd_buff	*get_curr_buff(t_list **fd_list, int fd)
{
	t_fd_buff 	*curr_fd_buff;
	t_list	*tmp;
	t_fd_buff   *curr;

	tmp = *fd_list;
	while (tmp)
	{
		curr_fd_buff = (t_fd_buff*)((tmp)->content);
		if (curr_fd_buff->fd == fd)
			return (curr_fd_buff);
		tmp = tmp->next;
	}
	curr_fd_buff = (t_fd_buff*)malloc(sizeof(t_fd_buff));
	if (curr_fd_buff)
	{
		curr_fd_buff->fd = fd;
		curr_fd_buff->lines = ft_strnew(BUFF_SIZE);
		if (!(curr_fd_buff->lines))
			return (NULL);
		tmp = ft_lstnew(curr_fd_buff, sizeof(curr_fd_buff));
		curr = (t_fd_buff*)(tmp->content);
		curr->fd = fd;
		ft_lstadd(fd_list, tmp);
		ft_memdel((void **)&curr_fd_buff);
		curr_fd_buff = (t_fd_buff*)((*fd_list)->content);
	}
	return (curr_fd_buff);
}

int			set_fd_buff_lines(t_fd_buff *curr_fd_buff, char *buff)
{
	char	*tmp;

	tmp = curr_fd_buff->lines;
	curr_fd_buff->lines = ft_strjoin(tmp, buff);
	//ft_strdel(&tmp);
	return (ft_strichr(buff, 10));
}

int			read_from_file(t_fd_buff *curr_fd_buff)
{	
	char	*buff;
	int		ret;
	int		pos;

	if (curr_fd_buff->filend == 1)
		return (0);
	buff = ft_strnew(BUFF_SIZE);
	if ((ret = read(curr_fd_buff->fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	buff[ret] = '\0';
	pos = set_fd_buff_lines(curr_fd_buff, buff);
	while (ret > 0 && pos < 0)
	{

		ret = read(curr_fd_buff->fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		pos = set_fd_buff_lines(curr_fd_buff, buff);
	}
	curr_fd_buff->filend = (ret == 0) ? 1 : 0;
	curr_fd_buff->len = ft_strlen(curr_fd_buff->lines);
	ft_strdel(&buff);
	return (ret < 0 ? ret : 1);
}

int			read_fd_buff(t_fd_buff *curr_fd_buff, char **line)
{
	int		pos;
	char	*tmp;
	char	*newline;
	char	*nextline;


	if (ft_strichr(curr_fd_buff->lines, 10) < 0)
		if(read_from_file(curr_fd_buff) < 0)
			return (-1);
	tmp = curr_fd_buff->lines;
	nextline = ft_strchr(curr_fd_buff->lines, 10);
	if (nextline)
		curr_fd_buff->lines = nextline + 1;
	pos = nextline ? nextline - tmp : ft_strlen(curr_fd_buff->lines);
	//ft_strdel(&tmp);
	newline = ft_strsub(tmp, 0, pos);
	tmp = *line;
	*line = newline;
	ft_strdel(&tmp);
	return (ft_strlen(*line) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_fd_buff			*curr_fd_buff;
	int					ret;

	if (fd < 0)
		return (-1);
	curr_fd_buff = get_curr_buff(&fd_list, fd);
	if (!curr_fd_buff)
		return (-1);
	if ((ret = read_fd_buff(curr_fd_buff, line)) == 1)
		return (ret);
	if (ret < 0)
		return (ret);
	if (ret == 0 && curr_fd_buff->filend == 1)
		return (0);
	return (1);
}


