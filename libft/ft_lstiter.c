/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:31:47 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/26 19:49:35 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
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
		f(curr);
		curr = nxt;
	}
}
