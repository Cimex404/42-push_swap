/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:15:01 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 17:15:04 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void	*str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) str)[i] = (unsigned char) c;
		i ++;
	}
	return (str);
}
