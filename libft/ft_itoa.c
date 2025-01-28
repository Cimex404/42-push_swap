/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:10:42 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:38:30 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	calclen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*copy(char *tmp, long nmb, int i, int len)
{
	tmp[len] = 0;
	while (nmb > 0)
	{
		tmp[i] = '0' + (nmb % 10);
		nmb /= 10;
		i --;
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		i;
	int		len;
	int		neg;
	long	nmb;

	neg = 0;
	nmb = n;
	if (nmb < 0)
		neg = 1;
	if (nmb == 0)
		return (ft_strdup("0"));
	if (neg == 1)
		nmb = -nmb;
	len = calclen(nmb) + neg;
	tmp = malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	if (neg)
		tmp[0] = '-';
	i = len - 1;
	tmp = copy(tmp, nmb, i, len);
	return (tmp);
}
