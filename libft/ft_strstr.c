/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:20:30 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/22 19:41:51 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *scanned, const char *searched)
{
	if (*searched == '\0')
		return ((char *)scanned);
	while (*scanned != '\0')
	{
		if (ft_strncmp(scanned, searched, ft_strlen(searched)) == 0)
			return ((char *)scanned);
		++scanned;
	}
	return (NULL);
}
