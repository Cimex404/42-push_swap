/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:46:17 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 10:28:41 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	len)
{
	size_t	i;

	i = 0;
	if (len > 0)
	{
		while (src[i] != 0 && i < (len - 1))
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = 0;
	}
	while (src[i] != 0)
		i ++;
	return (i);
}
