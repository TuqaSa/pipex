/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:46:01 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/21 16:47:41 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ptrlen(uintptr_t num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

void	ft_printp(unsigned long long ptr, int *counter)
{
	if (ptr == 0)
	{
		(*counter) += write(1, "(nil)", 5);
		return ;
	}
	(*counter) += write(1, "0x", 2);
	ft_putptr(ptr);
	(*counter) += ft_ptrlen(ptr);
}
