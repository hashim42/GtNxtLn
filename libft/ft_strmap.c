/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 00:35:29 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 16:59:17 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t			len;
	char			*ret;

	ret = NULL;
	len = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (ret != NULL)
		{
			while (*s != '\0')
			{
				*ret = f(*s);
				s++;
				ret++;
			}
			*ret = '\0';
		}
	}
	if (ret != NULL)
		return (ret - len);
	return (ret);
}
