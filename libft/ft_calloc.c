/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:23:12 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/12 09:40:51 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t	n, size_t	size)
{
	void	*ptr;

	ptr = (void *) malloc(size * n);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
