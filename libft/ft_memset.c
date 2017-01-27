/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:31:06 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/17 19:00:12 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	car;
	char			*s;

	i = 0;
	car = (unsigned char)c;
	s = (char *)str;
	while (i < n)
		s[i++] = car;
	return (str);
}
