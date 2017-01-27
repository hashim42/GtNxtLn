/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:29:32 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/21 13:50:35 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)dest;
	s2 = (char *)src;
	while (n-- > 0)
	{
		*s1 = *s2;
		if (*s1 == c)
			return (++s1);
		else
		{
			s1++;
			s2++;
		}
	}
	return (NULL);
}
