/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:21:29 by hazzout           #+#    #+#             */
/*   Updated: 2016/12/29 18:40:59 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>

typedef struct		s_fd_buff
{
	char				*line_buff;
	int					fd;
	struct s_fd_buff	next;
}					t_fd_buff;

# define BUFF_SIZE 1024

int		get_next_line(const int fd, char **line);

#endif
