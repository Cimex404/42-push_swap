/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:56:57 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/11 14:32:07 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	When in comes down to it, this is just a far less complicated version of
*	double_sort_utils. The reason this is much less code is that stack b is already
*	sorted in descending order, we now simply need to rotate stack to insert it into
*	the correct slot.
*/	

static int	get_position_a(t_stack *a, t_stack *b)
{
	int	i;

	i = get_index(*a, get_lowest(*a));
	if (get_highest(*a) > b->list[0])
		i = get_index(*a, *get_next(*a, b->list[0]));
	return (i);
}

void	sort_and_push_back(t_stack *a, t_stack *b)
{
	int	idx_a;

	idx_a = get_position_a(a, b);
	while (idx_a != 0)
	{
		if (idx_a <= a->len - idx_a && idx_a != 0)
			rra(a, 1);
		else if (idx_a > a->len - idx_a && idx_a != 0)
			rra(a, 1);
		idx_a = get_position_a(a, b);
	}
	pa(a, b);
}
