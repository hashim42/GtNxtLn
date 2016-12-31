/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:19:29 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/17 19:02:25 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (d == NULL)
		return (NULL);
	return (ft_strcpy(d, s));
}
