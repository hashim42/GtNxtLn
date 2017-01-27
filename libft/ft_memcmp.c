/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:22:43 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/21 16:59:32 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 1;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (s1 == s2)
		return (0);
	if (n == 0)
		return (0);
	if (*s1 != *s2 && n >= 1)
		return (*s1 - *s2);
	return (ft_memcmp(++s1, ++s2, --n));
}
