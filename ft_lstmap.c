/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:33:04 by mkorucu           #+#    #+#             */
/*   Updated: 2022/06/27 04:43:09 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*new_node;

	first_node = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			while (first_node)
			{
				new_node = first_node->next;
				(*del)(first_node->content);
				free(first_node);
				first_node = new_node;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_node, new_node);
		lst = lst->next;
	}
	return (first_node);
}
