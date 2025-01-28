/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:15:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:16:01 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

/*		STRUCT		*/
typedef struct s_stack
{
	long	*list;
	int		len;
}	t_stack;

/*		FUNCTIONS		*/
/*		Input		*/
int		get_true_argc(int ac, char **av);
int		fill_stack_a(t_stack *a, char *av_j, int start_index);

/*		Utils		*/
int		stack_is_sorted(t_stack stack);
int		stack_is_sorted_rev(t_stack stack);
int		double_error(t_stack stk);
int		get_highest(t_stack stk);
int		get_lowest(t_stack stk);
long	*get_next(t_stack stk, int nmb);
long	*get_former(t_stack stk, int nmb);
int		get_index(t_stack stk, int nmb);
int		mini(int one, int two);

/*		Algorithms		*/
void	simple_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *stk);
void	double_sort(t_stack *a, t_stack *b);
void	sort_and_push(t_stack *a, t_stack *b);
void	sort_and_push_back(t_stack *a, t_stack *b);

/*		Operations		*/
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	sa(t_stack *a, int prnt);
void	sb(t_stack *b, int prnt);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a, int prnt);
void	rb(t_stack *b, int prnt);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int prnt);
void	rrb(t_stack *b, int prnt);
void	rrr(t_stack *a, t_stack *b);

/*		Output		*/
void	ft_printf(char *str);

/*		Memory		*/
void	free_mem(t_stack stk);
void	free_split_allocation(char **ptr, int x);

#endif
