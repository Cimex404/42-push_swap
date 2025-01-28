/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:24:43 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/12 15:43:40 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, unsigned char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == 0)
		{
			if (c == 0)
				return ((char *)(str + i));
			return (NULL);
		}
		i ++;
	}
	return ((char *)(str + i));
}
