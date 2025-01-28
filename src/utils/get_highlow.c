/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_highlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:14:55 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:14:58 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	These functions are responsible for getting a specific value from the stacks
*	The highest value
*	The lowest value
*	The index of a value
*	The value of the next entry
*	The value of the previous entry
*/

int	get_highest(t_stack stk)
{
	int	cur;
	int	i;

	cur = stk.list[0];
	i = 0;
	while (i < stk.len)
	{
		if (stk.list[i] > cur)
			cur = stk.list[i];
		i ++;
	}
	return (cur);
}

int	get_lowest(t_stack stk)
{
	int	cur;
	int	i;

	cur = stk.list[0];
	i = 0;
	while (i < stk.len)
	{
		if (stk.list[i] < cur)
			cur = stk.list[i];
		i ++;
	}
	return (cur);
}

int	get_index(t_stack stk, int nmb)
{
	int	i;

	i = 0;
	while (stk.list[i] != nmb)
		i ++;
	return (i);
}

long	*get_next(t_stack stk, int nmb)
{
	int		i;
	long	*next;

	i = 0;
	next = NULL;
	while (i < stk.len)
	{
		if (stk.list[i] > nmb && (next == NULL || stk.list[i] < *next))
			next = &stk.list[i];
		i ++;
	}
	return (next);
}

long	*get_former(t_stack stk, int nmb)
{
	int		i;
	long	*former;

	i = stk.len - 1;
	former = NULL;
	while (i >= 0)
	{
		if (stk.list[i] < nmb && (former == NULL || stk.list[i] > *former))
			former = &stk.list[i];
		i --;
	}
	return (former);
}
