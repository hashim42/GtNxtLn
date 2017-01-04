/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_elem_by_val.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:45:32 by hazzout           #+#    #+#             */
/*   Updated: 2017/01/03 17:56:35 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_elem_by_val(t_list *lst, int (*f)(t_list *elem), int val)
{
	t_list *nxt;
	t_list *curr;

	nxt = NULL;
	curr = NULL;
	if (lst)
		curr = lst;
	while (curr)
	{
		nxt = curr->next;
		if (f(curr) == val)
			return (curr);
		curr = nxt;
	}
	return (NULL);
}

