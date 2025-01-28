/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:19:47 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:43:16 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char	*s1, const char	*s2)
{
	void	*ptr;
	size_t	i;
	size_t	c;

	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	c = 0;
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		((char *) ptr)[i] = s1[i];
		i ++;
	}
	while (s2[c] != 0)
	{
		((char *) ptr)[i + c] = s2[c];
		c ++;
	}
	((char *) ptr)[i + c] = 0;
	return (ptr);
}
