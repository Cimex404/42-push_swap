/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:13:01 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:13:04 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	These two functions take the two stacks and move the first instance of the
*	respective stack to the other, before that happens, the numbers of the receiving
*	stack get pushed back by one, to make space for the new number.
*	After the number has been moved, the donating stack moves all numbers up by one
*	to fill up the empty slot created from pushing the first number.
*/

void	pb(t_stack *a, t_stack *b, int prnt)
{
	int	i;

	i = b->len;
	while (i > 0)
	{
		b->list[i] = b->list[i - 1];
		i --;
	}
	b->list[0] = a->list[0];
	i = 0;
	while (i < a->len - 1)
	{
		a->list[i] = a->list[i + 1];
		i ++;
	}
	a->len --;
	b->len ++;
	if (prnt)
		ft_printf("pb");
}

void	pa(t_stack *a, t_stack *b, int prnt)
{
	int	i;

	i = a->len;
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		i --;
	}
	a->list[0] = b->list[0];
	i = 0;
	while (i < b->len - 1)
	{
		b->list[i] = b->list[i + 1];
		i ++;
	}
	b->len --;
	a->len ++;
	if (prnt)
		ft_printf("pa");
}
