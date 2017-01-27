/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:51:23 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/26 19:06:55 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst)
	{
		if (*alst)
		{
			next = (*alst)->next;
			if (next)
				ft_lstdel(&next, del);
			ft_lstdelone(alst, del);
		}
	}
}
