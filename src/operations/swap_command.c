/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:13:42 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:13:45 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	These functions can swap the first two integers of a stack
*	The prnt variable is used to decide whether or not to print the operation
*	When calling the ss function they should not be printed.
*/

void	sa(t_stack *a, int prnt)
{
	int	tmp;

	if (a->len >= 2)
	{
		tmp = a->list[0];
		a->list[0] = a->list[1];
		a->list[1] = tmp;
		if (prnt == 1)
			ft_printf("sa");
	}
}

void	sb(t_stack *b, int prnt)
{
	int	tmp;

	if (b->len >= 2)
	{
		tmp = b->list[0];
		b->list[0] = b->list[1];
		b->list[1] = tmp;
		if (prnt == 1)
			ft_printf("sb");
	}
}

void	ss(t_stack *a, t_stack *b, int prnt)
{
	sa(a, 0);
	sb(b, 0);
	if (prnt)
		ft_printf("ss");
}
