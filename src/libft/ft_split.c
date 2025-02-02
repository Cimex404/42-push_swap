/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:10:37 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 08:42:34 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Splits a string into an array of strings based on a delimiter
*	Returns an array of strings
*/

static void	free_mem(char **ptr, int x)
{
	while (x > 0)
		free(ptr[--x]);
	free(ptr);
}

static int	calcsubstrlen(const char *s, int c, int i, int totlen)
{
	int	len;

	len = 0;
	while (i < totlen && s[i] == c)
		i ++;
	while (i < totlen && s[i] != c)
	{
		len ++;
		i ++;
	}
	return (len);
}

int	spltnmb(const char *s, int c, int len)
{
	int	i;
	int	nmb;

	i = 0;
	nmb = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i ++;
		if (i < len && s[i] != c)
		{
			nmb ++;
			while (i < len && s[i] != c)
				i ++;
		}
	}
	return (nmb);
}

static char	**copy(char **ptr, const char *str, char c, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != c)
		{
			ptr[x] = malloc(calcsubstrlen(str, c, i, ft_strlen(str)) + 1);
			if (ptr[x] == NULL)
			{
				free_mem(ptr, x);
				return (NULL);
			}
			y = 0;
			while (str[i] != c && i < ft_strlen(str))
				ptr[x][y++] = str[i++];
			ptr[x++][y] = 0;
		}
		i ++;
	}
	ptr[x] = NULL;
	return (ptr);
}

char	**ft_split(const char *str, char c)
{
	char	**ptr;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(str) == 0)
	{
		ptr = malloc(sizeof(char *));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	ptr = malloc(sizeof(char *) * (spltnmb(str, c, ft_strlen(str)) + 1));
	if (ptr == NULL)
		return (NULL);
	while (str[i] == c)
		i ++;
	return (copy(ptr, str, c, i));
}
