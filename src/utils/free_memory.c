/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:14:28 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:14:30 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_stack stk)
{
	if (stk.list != NULL)
		free(stk.list);
}

void	free_split_allocation(char **ptr, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(ptr[i]);
		i ++;
	}
	free(ptr);
}
