/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:54:29 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/17 21:26:44 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		l;
	size_t		i;

	l = ft_strlen(src);
	i = 0;
	while (i < n)
	{
		dest[i] = (i <= l) ? src[i] : '\0';
		i++;
	}
	return (dest);
}
