/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnbrelems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:42:49 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 18:25:28 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstnbrelems(t_list **alst)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = *alst;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
