/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:23:53 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/02 18:37:09 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"

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
	tmp = NULL;
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
			*fd_buff = new_fd_buff;
	}	
	return (*fd_buff);
}

int			read_file(t_fd_buff *curr_fd_buff, char **line)
{	
	char *buff;
	int ret;
	int pos;

	buff = ft_strnew(BUFF_SIZE);
	ret = read(curr_fd_buff->fd, buff, BUFF_SIZE);
	if (ret == -1 || ret == 0)
		return (ret);
	buff[ret] = '\0';
	while ((pos = ft_strichr(buff, 10)) == -1 && ret != -1)
	{
		curr_fd_buff->line = line_join_buff(curr_fd_buff->line, buff);
		ret = read(curr_fd_buff->fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (ret);
		buff[ret] = '\0';
		pos = (ret == 0) ? 0 : pos;
	}
	curr_fd_buff->line = line_join_buff(curr_fd_buff->line, ft_strsub(buff, 0, pos));
	*line = ft_strdup(curr_fd_buff->line);
	free(curr_fd_buff->line);
	curr_fd_buff->line = ft_strsub(buff, pos + 1, ret - pos + 1);
	ft_strdel(&buff);
	return (1);
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
		free(tmp);		
		return (1);
	}
	return (pos);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_buff	*fd_buff;
	t_fd_buff			*curr_buff;
	int					pos;
	int					ret;

	curr_buff = get_curr_buff(fd, &fd_buff);
	ret = read_fd_buff(curr_buff, line);
	ft_putstr(*line);
	ft_putstr("\n");
	if (ret == 1)
		return (ret);
	if (ret == -1)
		ret = read_file(curr_buff, line);
	if (ret == -1 || ret == 0)
		return (ret);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int fd2;
	int ret;
	char **line;

	line  = (char **)malloc(sizeof(char*) * BUFF_SIZE);
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		while ((ret = get_next_line(fd, line) == 1))
		{
			//ft_putstr(*line);
			//ft_putstr("\n");
			;
		}
		close(fd);
	}
	return (0);
}
