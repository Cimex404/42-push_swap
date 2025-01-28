/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:19:47 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:45:19 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	chr_is_contained(const char	*set, char chr)
{
	size_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == chr)
			return (1);
		i ++;
	}
	return (0);
}

static int	atleastone(int n)
{
	if (n < 1)
		return (1);
	return (n);
}

char	*ft_strtrim(const char	*s1, const char	*set)
{
	void	*ptr;
	size_t	i;
	size_t	f;
	size_t	l;

	i = 0;
	f = 0;
	l = ft_strlen(s1);
	while (s1[f] != 0 && chr_is_contained(set, s1[f]))
		f ++;
	while (s1[i ++] != 0 && chr_is_contained(set, s1[l - 1]))
		l --;
	ptr = (char *) malloc(atleastone(l - f + 1));
	i = f;
	if (ptr == NULL)
		return (NULL);
	while (i < l)
	{
		((char *) ptr)[i - f] = s1[i];
		i ++;
	}
	((char *) ptr)[i - f] = 0;
	return (ptr);
}
