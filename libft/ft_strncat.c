/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:46:19 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 04:25:40 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *dst;

	dst = dest;
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && n-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (dest);
}
