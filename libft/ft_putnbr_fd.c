/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:01:21 by jgraf             #+#    #+#             */
/*   Updated: 2024/10/15 10:13:24 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nmb;

	nmb = n;
	if (nmb < 0)
	{
		ft_putchar_fd('-', fd);
		nmb = -nmb;
	}
	if (nmb >= 10)
		ft_putnbr_fd(nmb / 10, fd);
	ft_putchar_fd(nmb % 10 + '0', fd);
}
