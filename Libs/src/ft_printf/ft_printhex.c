/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:10:54 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/22 11:11:00 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, c);
		ft_puthex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar(num - 10 + 'a');
			if (c == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

size_t	ft_hexlen(unsigned int value)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		len++;
		value /= 16;
	}
	return (len);
}

void	ft_printhex(unsigned int value, const char c, int *counter)
{
	if (value == 0)
		(*counter) += ft_putchar('0');
	else
	{
		ft_puthex(value, c);
		(*counter) += ft_hexlen(value);
	}
}
