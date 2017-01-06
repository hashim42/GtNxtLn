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
		curr_fd_buff->line = ft_strnew(BUFF_SIZE);
		if (!(curr_fd_buff->line))
			return (NULL);
		size = sizeof(curr_fd_buff);
		ft_lstadd(fd_list, ft_lstnew(curr_fd_buff, size));
	}
	return (curr_fd_buff);
}

void str_join_and_free(char **line, char *str)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, str);
	ft_strdel(&tmp);
}

int			read_from_file(t_fd_buff *curr_fd_buff, char **line)
{	
	char	*buff;
	char	*newline;
	int		pos;
	int		ret;

	pos = -1;
	ret = 1;
	buff = ft_strnew(BUFF_SIZE);
	newline = NULL;
	while ( pos == -1 && ret)
	{
		ret = read(curr_fd_buff->fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (ret);
		buff[ret] = '\0';
		pos = ft_strichr(buff, 10);
		if (pos >= 0)
		{
			str_join_and_free(line, ft_strsub(buff, 0, pos));
			newline = ft_strsub(buff, pos + 1, ret - pos);
			str_join_and_free(&curr_fd_buff->line, newline);
		}
		else
			str_join_and_free(line, buff);
		pos = (ret == 0 ? 0 : pos);
	}
	return (ret);
}

int			read_fd_buff(t_fd_buff *curr_fd_buff, char **line)
{
	int		pos;
	int		len;
	char	*tmp;

	pos = -1;
	len = 0;
	if ((pos = ft_strichr(curr_fd_buff->line, 10)) != -1)
	{
		*line = ft_strsub(curr_fd_buff->line, 0, pos);
		tmp = curr_fd_buff->line;
		len = ft_strlen(tmp);
		curr_fd_buff->line = ft_strsub(curr_fd_buff->line, pos + 1, len - pos);
		ft_strdel(&tmp);		
		return (1);
	}
	return (pos);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*fd_list;
	t_fd_buff			*curr_buff;
	int					retf;
	int					retb;

	curr_buff = get_curr_buff(&fd_list, fd);
	retb = read_fd_buff(curr_buff, line);
	retf = -1;
	if (retb == 1)
		return (retb);
	if (retb == -1)
		retf = read_from_file(curr_buff, line);
	if (retf > 0)
		return (1);
	return (0);
}
