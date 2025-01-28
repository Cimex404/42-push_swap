/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:02 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 10:28:24 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (s2[i] == 0)
		return ((char *) s1);
	while (s1[i] != 0 && i < n)
	{
		c = 0;
		while (s1[i + c] == s2[c] && (i + c) < n)
		{
			if (s2[c + 1] == 0)
				return ((char *)(s1 + i));
			c ++;
		}
		i ++;
	}
	return (0);
}
