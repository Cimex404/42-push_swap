/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:45:09 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/11 14:32:30 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This is the double sort algorithm. It is called that because the algorithm
*	sorts everything into stack b and then back to stack a.
*	To start, we push two values to stack b to create a highest and lowest number there.
*	Then we apply the sort and push function to stack a.
*	When there are only three entries left in stack a, we call the sort_three algorithm.
*	After stack a is sorted in ascending oder, and stack b in descending order,
*	we push every entry from stack b back to stack a.
*	Lastly we rotate or reverse-rotate (whichever takes less operations) stack a
*	until the smallest value is at the top.
*/

void	double_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (a->len > 3)
		pb(a, b);
	if (a->len > 3)
		pb(a, b);
	while (a->len > 3 && !stack_is_sorted(*a))
		sort_and_push(a, b);
	if (a->len == 3)
		sort_three(a);
	while (b->len > 0)
		sort_and_push_back(a, b);
	i = get_index(*a, get_lowest(*a));
	while (i != 0)
	{
		if (i <= a->len - i)
			ra(a, 1);
		else
			rra(a, 1);
		i = get_index(*a, get_lowest(*a));
	}
}
