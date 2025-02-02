/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:15:09 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:15:12 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These functions create all entries for stack a using the split function
*	from the libft.
*	They also check whether a specific value is over, or under the integer limits
*	and throw an error if so.
*/

static long	check_limit(long val)
{
	if (val > INT_MAX || val < INT_MIN)
		return (LONG_MIN);
	return (val);
}

int	fill_stack_a(t_stack *a, char *av_j, int start_index)
{
	int		i;
	int		k;
	char	**nmb;

	k = start_index;
	i = 0;
	nmb = ft_split(av_j, ' ');
	if (nmb == NULL)
		return (ft_printf_err("Error"), -1);
	while (nmb[i] != NULL)
	{
		a->list[i + k] = ft_atoi(nmb[i]);
		if (check_limit(a->list[i + k]) == LONG_MIN)
		{
			free_split_allocation(nmb, i);
			return (ft_printf_err("Error"), -1);
		}
		i ++;
	}
	free_split_allocation(nmb, i);
	return (i);
}

int	get_true_argc(int ac, char **av)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	while (i < ac)
	{
		cnt += spltnmb(av[i], ' ', ft_strlen(av[i]));
		i ++;
	}
	return (cnt);
}
