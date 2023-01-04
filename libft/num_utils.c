/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:31:01 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/12 11:04:58 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_len_long(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n < 10)
		i++;
	else
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

void	ft_putnbr_nosign(long int num, int fd)
{
	if (num < 0)
	{
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_nosign(num / 10, fd);
		ft_putnbr_nosign(num % 10, fd);
	}
	else
	{
		ft_putchar_fd(num + 48, fd);
	}
}
