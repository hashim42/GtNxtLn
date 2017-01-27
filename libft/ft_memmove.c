/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:01:45 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/19 15:11:29 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;
	int			i;

	s1 = (char *)str1;
	s2 = (char *)str2;
	i = n;
	if (s1 < s2)
		while (i-- > 0)
			*s1++ = *s2++;
	if (s1 > s2)
		while (n-- > 0)
			s1[n] = s2[n];
	return (str1);
}
