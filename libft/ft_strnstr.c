/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 00:41:11 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 16:19:43 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *scanned, const char *searched, size_t len)
{
	size_t	srchl;
	size_t	scnl;

	if (len == 0)
		return (NULL);
	if (*searched == '\0')
		return ((char *)scanned);
	srchl = ft_strlen(searched);
	scnl = ft_strlen(scanned);
	if (len < srchl || scnl < srchl)
		return (NULL);
	while (*scanned != '\0' && len-- >= srchl)
	{
		if (ft_strncmp(scanned, searched, srchl) == 0)
			return ((char *)scanned);
		++scanned;
	}
	return (NULL);
}
