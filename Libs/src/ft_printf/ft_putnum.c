/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:31:00 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/21 17:03:08 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_numlen(int arg)
{
	size_t	count;

	count = 0;
	if (arg == 0)
		return (1);
	if (arg < 0)
		arg = -arg;
	while (arg)
	{
		count++;
		arg /= 10;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	}
}

void	ft_putnum(int arg, int *counter)
{
	ft_putnbr(arg);
	(*counter) += ft_numlen(arg);
}
