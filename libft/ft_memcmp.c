/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbonn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:59:06 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 10:29:54 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return ((int)(t1[i] - t2[i]));
		i ++;
	}
	return (0);
}
