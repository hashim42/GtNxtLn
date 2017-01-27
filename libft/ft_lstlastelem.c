/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:22:16 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 18:24:24 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlastelem(t_list **alst)
{
	t_list *lst;

	lst = *alst;
	while (lst->next)
		lst = lst->next;
	return (lst);
}
