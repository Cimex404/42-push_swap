/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:44 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 17:14:47 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	move(char *d, const char *s, size_t n)
{
	size_t	i;

	if (s < d && d < s + n)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i --;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i ++;
		}
	}
}

void	*ft_memmove(void	*dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (char *) dest;
	s = (const char *) src;
	move(d, s, n);
	return (d);
}
