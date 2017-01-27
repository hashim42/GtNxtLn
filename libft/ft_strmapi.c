/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 01:06:01 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 18:28:19 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*ret;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret != NULL)
	{
		while (*s != '\0')
		{
			*ret = f(i, *s);
			s++;
			ret++;
			i++;
		}
		*ret = '\0';
	}
	ret = (ret != NULL ? ret - len : NULL);
	return (ret);
}
