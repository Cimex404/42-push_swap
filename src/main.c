/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:15:36 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:15:40 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	This function goes through all arguments and fills stack a with the input
*	Stack b is being filled with 0's
*/

static int	fill_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int		len;
	int		i;
	int		c;
	int		k;
	int		l;

	len = 0;
	c = 1;
	k = 0;
	l = 0;
	while (c < ac)
	{
		i = fill_stack_a(a, av[c], k);
		if (i == -1)
			return (-1);
		while (l < i)
		{
			b->list[k + l] = 0;
			l ++;
		}
		k += i;
		len += i;
		c ++;
	}
	return (len);
}


/*	The main initializes two empty stacks that are filled with the input.
*	The length of the stacks is set to the number of integers for stack a and 0 for stack b
*	Then the function checks if the given string is already sorted. If it is sorted, the program will end.
*	If there are less than 5 numbers in stack a. The program will execute a much simpler version of the
*	sorting algorithm.
*	Otherwise a more complex sorting algorithm is applied.
*/

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	a.list = malloc(sizeof(int *) * get_true_argc(ac, av));
	b.list = malloc(sizeof(int *) * get_true_argc(ac, av));
	if (a.list == NULL || b.list == NULL)
		return (free_stack(a), free_stack(b), 1);
	a.len = fill_stack(&a, &b, ac, av);
	b.len = 0;
	if (a.len == 0 || stack_is_sorted(a))
		return (free_stack(a), free_stack(b), 0);
	if (!double_error(a))
		return (free_stack(a), free_stack(b), ft_printf_err("Error"), 1);
	if (a.len < 5)
		simple_sort(&a, &b);
	else
		double_sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
