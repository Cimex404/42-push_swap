/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:46:06 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 10:29:02 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t	len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (dest[i] != 0)
		i ++;
	if (i >= len)
	{
		while (src[c] != 0)
			c ++;
		return (len + c);
	}
	while (c < (len - i - 1) && src[c] != 0)
	{
		dest[i + c] = src[c];
		c ++;
	}
	dest[i + c] = 0;
	while (src[c] != 0)
		c ++;
	return (i + c);
}
