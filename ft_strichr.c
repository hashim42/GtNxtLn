/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 11:43:49 by hazzout           #+#    #+#             */
/*   Updated: 2016/12/30 11:49:52 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(const char *str, int c)
{
	char *memchr;

	memchr = (char *)ft_memchr(str, c, ft_strlen(str) + 1);
	if (memchr)
		return (memchr - str);
	return (-1);
}
