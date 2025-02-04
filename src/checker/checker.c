/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:10:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/03 09:11:01 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void	perform_operation(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b, 0);
	else
	{
		ft_printf_err("Error");
		free_stack(*a);
		free_stack(*b);
		exit(1);
	}
}

static void	run_checker(t_stack *a, t_stack *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		perform_operation(op, a, b);
	}
	if (b->len == 0 && stack_is_sorted(*a))
		ft_printf("OK");
	else
		ft_printf("KO");
}

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

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	a.list = malloc(sizeof(int *) * get_true_argc(ac, av));
	b.list = malloc(sizeof(int *) * get_true_argc(ac, av));
	if (a.list == NULL || b.list == NULL)
		return (free_stack(a), free_stack(b), ft_printf_err("Error"), 1);
	a.len = fill_stack(&a, &b, ac, av);
	b.len = 0;
	run_checker(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
