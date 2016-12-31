/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 01:51:19 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 16:25:27 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*dst;
	int		l;
	size_t	dl;
	size_t	sl;

	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	l = n - dl - 1;
	if (l > 0)
		dst = ft_strncat(dest, src, l);
	return ((n > dl ? dl : n) + sl);
}
