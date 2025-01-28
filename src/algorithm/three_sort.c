/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:16:31 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:16:34 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This is a very complicated to look at, hard-coded three sort algorithm.
*	It is quite simple though:
*	With three values, there are only six possible ways to configure them.
*	You can see that there are three if statements, two of them are combined
*	with an or statement. The thrid if statement does not have an or statement
*	because that sixth case would check for the one configuration where the numbers
*	are already sorted.
*	The sorting happens in a while loop, because the maximum number of
*	operations needed is 2.
*/

void	sort_three(t_stack *stk)
{
	if (stack_is_sorted(*stk))
		return ;
	while (!stack_is_sorted(*stk))
	{
		if ((stk->list[0] > stk->list[1] && stk->list[0] < stk->list[2])
			|| (stk->list[1] > stk->list[2] && stk->list[1] < stk->list[0]))
			sa(stk, 1);
		if ((stk->list[2] > stk->list[0] && stk->list[2] < stk->list[1])
			|| (stk->list[0] > stk->list[2] && stk->list[0] < stk->list[1]))
			rra(stk, 1);
		if (stk->list[2] > stk->list[1] && stk->list[2] < stk->list[0])
			ra(stk, 1);
	}
}
