/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:16:17 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:16:20 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This is the simple sort.
*	If there are three or two entries, there are hard coded cases.
*	If there are more, the next biggest value to the last is rotated to the top
*	and then pushed to stack b.
*	When there are no entries left in stack a, all entries are pushed from b to a.
*	Now, stack a is fully sorted in ascending order.
*/

void	simple_sort(t_stack *a, t_stack *b)
{
	int	index;

	if (a->len == 3 || a->len == 2)
	{
		if (a->len == 3)
			sort_three(a);
		if (a->len == 2)
			sa(a, 1);
		return ;
	}
	index = get_index(*a, get_lowest(*a));
	while (a->len > 1)
	{
		while (a->list[0] != get_lowest(*a))
		{
			if (index <= a->len - index)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	while (b->len > 0)
		pa(a, b, 1);
}
