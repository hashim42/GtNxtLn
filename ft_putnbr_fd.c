/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:13:21 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 13:48:38 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ng;
	int		lim;
	int		ldg;

	ng = '-';
	lim = (n == -2147483648 ? 1 : 0);
	if (n < 0)
		write(fd, &ng, 1);
	ldg = lim ? (n % 10) * -1 : 0;
	n = lim ? (n / 10) * -1 : n;
	n = n < 0 && !lim ? -n : n;
	if (n <= 9 && n >= -9)
	{
		n = (n < 0 ? -n : n) + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (lim)
		ft_putnbr_fd(ldg, fd);
}
