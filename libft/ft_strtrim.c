/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:19:49 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/23 00:31:32 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*st;
	size_t	len;
	size_t	bgn;
	size_t	end;

	bgn = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	end = len - 1;
	while (s[bgn] != '\0' && ft_isspace(s[bgn]))
		++bgn;
	while (ft_isspace(s[end]) && end >= bgn)
		--end;
	len = end - bgn + 1;
	st = ft_strnew(len);
	if (st == NULL)
		return (st);
	while (s[bgn] != '\0' && bgn <= end)
		*st++ = s[bgn++];
	*st = '\0';
	return (st - len);
}
