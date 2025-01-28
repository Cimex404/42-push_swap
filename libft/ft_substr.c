/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:01:55 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:45:40 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tmp = (char *)malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	while (s[i] != 0 && len > 0)
	{
		if (i >= start)
		{
			tmp[j] = s[i];
			j ++;
			len --;
		}
		i ++;
	}
	tmp[j] = 0;
	return (tmp);
}
