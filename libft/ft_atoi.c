/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:11:54 by jgraf             #+#    #+#             */
/*   Updated: 2025/01/10 12:11:57 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	invalid_chars(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i])
			&& str[i] != '-' && str[i] != '+')
			return (1);
		i ++;
	}
	return (0);
}

long	ft_atoi(const char	*str)
{
	long	val;
	int		sign;
	int		i;

	val = 0;
	sign = 1;
	i = 0;
	if (invalid_chars(str))
		return (LONG_MIN);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
		if (!ft_isdigit(str[i]))
			return (LONG_MIN);
	}
	while (ft_isdigit(str[i]))
	{
		val *= 10;
		val += str[i ++] - '0';
	}
	return (val * sign);
}
