/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:14:01 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:14:04 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	This function steps through the stack and returns 0 if there are two instances
*	of the same integer.
*/

int	double_error(t_stack stk)
{
	int	i;
	int	j;

	i = 0;
	while (i < stk.len)
	{
		j = 0;
		while (j < stk.len)
		{
			if (stk.list[i] == stk.list[j] && i != j)
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}
