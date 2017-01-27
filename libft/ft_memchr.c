/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:14:41 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 18:36:05 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*s;

	if (n == 0)
		return (NULL);
	car = (unsigned char)c;
	s = (const unsigned char *)str;
	while (*s != car && --n > 0)
	{
		s++;
		str++;
	}
	if (*s != car)
		return (NULL);
	return ((void *)str);
}
