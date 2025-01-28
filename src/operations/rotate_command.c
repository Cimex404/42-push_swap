/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:13:13 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:13:16 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	These three functions rotate the stack, that means that the amount of integers
*	stays the same, but the first number becomes the last, the second number becomes
*	the first and so on...
*	These functions also have a special flag that decides whether or not the operation
*	is printed. This is because the rr (rotate both stacks) needs to execute both ra and rb
*	but prints "rr" instead of "ra" and "rb"
*/

void	rb(t_stack *b, int prnt)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b->list[0];
	while (i < b->len - 1)
	{
		b->list[i] = b->list[i + 1];
		i ++;
	}
	b->list[b->len - 1] = tmp;
	if (prnt == 1)
		ft_printf("rb");
}

void	ra(t_stack *a, int prnt)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a->list[0];
	while (i < a->len - 1)
	{
		a->list[i] = a->list[i + 1];
		i ++;
	}
	a->list[a->len - 1] = tmp;
	if (prnt == 1)
		ft_printf("ra");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr");
}
