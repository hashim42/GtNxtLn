/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:21:29 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/25 15:16:45 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

typedef struct	s_fd_buff
{
	char	*lines;
	int		fd;
	int		filend;
	int		len;
}				t_fd_buff;

# define BUFF_SIZE 255

int				get_next_line(const int fd, char **line);

#endif
