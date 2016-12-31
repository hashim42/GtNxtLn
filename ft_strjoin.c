/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:07:45 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/22 23:17:22 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*j;
	size_t	l;

	j = NULL;
	l = 0;
	if (s1 == NULL || s2 == NULL)
		return (j);
	l = ft_strlen(s1) + ft_strlen(s2);
	j = ft_strnew(l);
	if (j == NULL)
		return (j);
	while (*s1 != '\0')
		*j++ = *s1++;
	while (*s2 != '\0')
		*j++ = *s2++;
	*j = '\0';
	return (j - l);
}
