/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:00:49 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/25 11:25:14 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_nodes(t_list **list, void (*del)(void*))
{
	t_list	*node;

	while (*list != NULL)
	{
		node = *list;
		*list = (*list)-> next;
		del(node -> content);
		free(node);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last_node;

	new_list = NULL;
	last_node = NULL;
	while (lst != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
		{
			free_nodes(&new_list, del);
			del(f(lst -> content));
			return (NULL);
		}
		new_node -> content = f(lst -> content);
		new_node -> next = NULL;
		if (new_list == NULL)
			new_list = new_node;
		else
			last_node -> next = new_node;
		last_node = new_node;
		lst = lst -> next;
	}
	return (new_list);
}
