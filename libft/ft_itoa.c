/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:40:31 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/19 19:16:32 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char		*ft_itoa(int n)
{
	char	tab[11];
	char	*ret;
	int		i;
	int		ng;
	int		j;

	i = 0;
	j = 0;
	ng = n < 0 ? 1 : 0;
	if (n == 0)
		tab[i++] = '0';
	while (n != 0)
	{
		tab[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (ng == 1)
		tab[i++] = '-';
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	while (i-- > 0)
		ret[j++] = tab[i];
	ret[j] = '\0';
	return (ret);
}
