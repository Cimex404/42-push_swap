/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:10:28 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:36:05 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Converts a string to an integer

static int	is_whitespace(unsigned char c)
{
	if (c == '\t' || c == '\v'
		|| c == '\r' || c == '\n'
		|| c == '\f' || c == ' '
		|| c == '	')
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int	val;
	int	sign;
	int	i;

	val = 0;
	sign = 1;
	i = 0;
	while (str[i] <= ' ' || str[i] > 126)
	{
		if (!is_whitespace(str[i]))
			return (0);
		i ++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i ++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += str[i ++] - '0';
	}
	return (val * sign);
}
