/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:45:14 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 13:40:11 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *curr;
	t_list *nxt;

	curr = NULL;
	nxt = NULL;
	if (lst)
	{
		if (lst->next)
			nxt = ft_lstmap(lst->next, f);
		curr = f(lst);
		curr->next = nxt;
	}
	return (curr);
}
