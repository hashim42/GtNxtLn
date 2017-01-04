/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:21:29 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/04 02:33:08 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

typedef struct		s_fd_buff
{
	char				*line;
	int					fd;
}					t_fd_buff;

typedef t_list t_fd_list;

# define BUFF_SIZE 1 

int		get_next_line(const int fd, char **line);

#endif
