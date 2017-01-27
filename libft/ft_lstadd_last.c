/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:18:21 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 18:23:43 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = NULL;
	if (new)
	{
		if (alst)
			lst = ft_lstlastelem(alst);
		if (lst)
			lst->next = new;
	}
}
