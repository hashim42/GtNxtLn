/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:23:53 by hazzout           #+#    #+#             */
/*   Updated: 2016/12/31 05:31:59 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"

int         get_next_buff(const int fd, char *buff)
{
	int ret;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	return (ret);
}

char        *line_sub_buff(char *buff, int pos)
{
	char    *ret;
	int     len;

	len  = ft_strlen(buff);
	ret = ft_strsub(buff, pos + 1 , len - pos + 1);
	return (ret);
}

char        *line_join_buff(char *line, char *buff)
{
	char *tmp;
	char *ret;

	tmp = line;
	ret = ft_strjoin(line, buff);
	ft_strdel(&tmp);
	return (ret);
}

int     lstnbrelems(t_fd_buff **fd_buff)
{
	t_fd_buff  *lst;
	int     i;

	i = 0;
	lst = *fd_buff;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_fd_buff	*get_curr_buff(int fd, t_fd_buff **fd_buff)
{
	t_fd_buff *new_fd_buff;
	t_fd_buff *curr_fd_buff;
	t_fd_buff *tmp;

	curr_fd_buff = *fd_buff;
	while (curr_fd_buff)
	{
		if ((curr_fd_buff)->fd == fd)
			return (curr_fd_buff);
		tmp = curr_fd_buff;
		curr_fd_buff = (curr_fd_buff)->next;
	}
	new_fd_buff = (t_fd_buff*)malloc(sizeof(t_fd_buff));
	if (new_fd_buff)
	{
		new_fd_buff->fd = fd;
		new_fd_buff->next = NULL;
		new_fd_buff->line = ft_strnew(BUFF_SIZE);
		if (!(new_fd_buff->line))
			return (NULL);
		if (tmp)
			tmp->next = new_fd_buff;
		if (lstnbrelems(fd_buff) == 0)
		   *fd_buff	= new_fd_buff;
	} 
	return (*fd_buff);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_buff	*fd_buff;
	t_fd_buff			*curr_buff;
	char				*buff;
	int					pos;
	int					ret;

	curr_buff = get_curr_buff(fd, &fd_buff);
	buff = ft_strnew(BUFF_SIZE);
	ret = get_next_buff(fd, buff);
	if (ret == -1 || ret == 0)
		return (ret);
	ft_putnbr(ret);
	ft_putstr("\n");
	while ((pos = ft_strichr(buff, 10)) < 0)
	{
		curr_buff->line = line_join_buff(curr_buff->line, buff);
		ret = get_next_buff(fd, buff);
		if (ret == -1)
			return (ret);
		pos = (ret == 0) ? 0 : pos;
	}
	curr_buff->line = line_join_buff(curr_buff->line, ft_strsub(buff, 0, pos));
	*line = ft_strdup(curr_buff->line);
	free(curr_buff->line);
	curr_buff->line = line_sub_buff(buff, pos);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int fd2;
	int ret;
	char **line;

	line  = (char **)malloc(sizeof(char*));
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		while ((ret = get_next_line(fd, line) == 1))
		{
			ft_putstr(*line);
			ft_putstr("\n");
		}
		get_next_line(fd, line);
		ft_putstr(*line);
		ft_putstr("\n");
		close(fd);
	}
	return (0);
}
