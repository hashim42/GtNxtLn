/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:36:58 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/22 18:04:54 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 1;
	if (s1 == s2)
		return (0);
	if (n == 0)
		return (0);
	if (*s1 == '\0' && *s1 == *s2)
		return (0);
	if (*s1 != *s2 && n >= 1)
		return (*s1 - *s2);
	return (ft_strncmp(++str1, ++str2, --n));
}
