/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:13:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:13:33 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//	These functions work the exact same as the rotate functions just in the other direction

void	rrb(t_stack *b, int prnt)
{
	int	i;
	int	tmp;

	i = b->len - 1;
	tmp = b->list[b->len - 1];
	while (i > 0)
	{
		b->list[i] = b->list[i - 1];
		i --;
	}
	b->list[0] = tmp;
	if (prnt == 1)
		ft_printf("rrb");
}

void	rra(t_stack *a, int prnt)
{
	int	i;
	int	tmp;

	i = a->len - 1;
	tmp = a->list[a->len - 1];
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		i --;
	}
	a->list[0] = tmp;
	if (prnt == 1)
		ft_printf("rra");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr");
}
