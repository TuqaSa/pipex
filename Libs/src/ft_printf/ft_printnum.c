/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:48:24 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/22 19:43:06 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int num)
{
	char	n;

	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			ft_putchar('-');
			num = -num;
		}
		if (num > 9)
		{
			ft_putnbr(num / 10);
			ft_putnbr(num % 10);
		}
		else
		{
			n = num + '0';
			ft_putchar(n);
		}
	}
}

void	ft_putnum(int num, int *counter)
{
	ft_putnbr(num);
	(*counter) += ft_numlen(num);
}

void	ft_putun(unsigned int num, int *counter)
{
	if (num >= 10)
		ft_putun(num / 10, counter);
	ft_putchar(num % 10 + '0');
	(*counter)++;
}
