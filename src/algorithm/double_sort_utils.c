/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:00:12 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/11 14:32:41 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These utils are responsible for pushing the first value of stack a to the
*	correct position in stack b.
*	Essentially, the algorithm calculates the number with the least amount of
*	operations necessary to bring it to the correct position in stack b.
*	The "cost" (needed number of operations) is calculated by adding the number
*	of operations needed to bring the number to the top of stack a + the number of
*	operations to rotate stack b into the correct position. (e.g. 8 needs to be inserted
*	between 12 and 5)
*/

static int	get_b(t_stack *a, t_stack *b, int idx_a)
{
	int	i;

	i = get_index(*b, get_highest(*b));
	if (get_lowest(*b) < a->list[idx_a])
		i = get_index(*b, *get_former(*b, a->list[idx_a]));
	return (i);
}

static int	calc_cheap_a(t_stack *a, t_stack *b)
{
	int	cost;
	int	lowest_cost;
	int	lowest_index;
	int	i;
	int	r;

	i = 0;
	lowest_index = INT_MAX;
	lowest_cost = INT_MAX;
	while (i < a->len)
	{
		cost = mini(i, a->len - i);
		r = get_b(a, b, i);
		cost += mini(r, b->len - r);
		if (cost < lowest_cost)
		{
			lowest_index = i;
			lowest_cost = cost;
		}
		i ++;
	}
	return (a->list[lowest_index]);
}

static void	rotate_stacks(t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	static long	v = LONG_MAX;

	if (v == LONG_MAX)
		v = calc_cheap_a(a, b);
	i = get_index(*a, v);
	j = get_b(a, b, i);
	if (i <= a->len - i && j <= b->len - j && i != 0 && j != 0)
		rr(a, b);
	else if (i > a->len - i && j > b->len - j && i != 0 && j != 0)
		rrr(a, b);
	else
	{
		if (i <= a->len - i && i != 0)
			ra(a, 1);
		else if (i > a->len - i && i != 0)
			rra(a, 1);
		if (j <= b->len - j && j != 0)
			rb(b, 1);
		else if (j > b->len - j && j != 0)
			rrb(b, 1);
	}
	if (get_index(*a, v) + get_b(a, b, get_index(*a, v)) == 0)
		v = LONG_MAX;
}

void	sort_and_push(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	val;

	val = calc_cheap_a(a, b);
	while (1)
	{
		i = get_index(*a, val);
		j = get_b(a, b, i);
		if (i == 0 && j == 0)
			break ;
		rotate_stacks(a, b);
	}
	pb(a, b);
}
