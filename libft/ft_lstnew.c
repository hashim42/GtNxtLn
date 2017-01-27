/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:04:34 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/27 14:04:23 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = NULL;
	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		if (content)
		{
			lst->content = (void *)malloc(content_size);
			lst->content = ft_memcpy(lst->content, content, content_size);
		}
		else
			lst->content = NULL;
		lst->content_size = (content == NULL ? 0 : content_size);
		lst->next = NULL;
	}
	return (lst);
}
