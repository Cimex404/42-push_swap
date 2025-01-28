/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:25:20 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:42:46 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char	*src)
{
	void	*ptr;
	int		i;
	int		len;

	len = 0;
	while (src[len] != 0)
		len ++;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		((char *) ptr)[i] = src[i];
		i ++;
	}
	((char *) ptr)[len] = 0;
	return (ptr);
}
