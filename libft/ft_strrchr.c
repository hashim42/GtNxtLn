/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:01:57 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/25 12:31:40 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrchr(const void *str, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*s;
	const unsigned char	*sr;
	size_t				len;

	car = (unsigned char)c;
	len = ft_strlen(str);
	s = (const unsigned char *)str;
	sr = (const unsigned char *)str;
	while (*s != '\0' && --n > 0)
	{
		if (*s == car)
			sr = s;
		s++;
	}
	if (*s == car && car == '\0')
		return ((void *)s);
	if (*sr != car && (*s == '\0' || n == 0))
		return (0);
	return ((void *)sr);
}

char		*ft_strrchr(const char *str, int c)
{
	return ((char *)ft_memrchr(str, c, ft_strlen(str) + 1));
}
