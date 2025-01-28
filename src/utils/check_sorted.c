/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:14:14 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:14:16 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	These two functions will return 1 if the stack is sorted in ...

//	... ascending order.
int	stack_is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.len - 1)
	{
		if (stack.list[i] > stack.list[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

//	... descending order.
int	stack_is_sorted_rev(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.len - 1)
	{
		if (stack.list[i] < stack.list[i + 1])
			return (0);
		i ++;
	}
	return (1);
}
