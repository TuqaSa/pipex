/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:46:46 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/23 16:07:01 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++(*counter);
		++i;
	}
	return (1);
}

void	ft_format(va_list str, char c, int *counter)
{
	if (c == 'c')
		*counter += ft_putchar(va_arg(str, int));
	else if (c == 's')
		ft_putstr(va_arg(str, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_putnum(va_arg(str, int), counter);
	else if (c == 'p')
		ft_printp(va_arg(str, unsigned long long), counter);
	else if (c == 'u')
		ft_putun(va_arg(str, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(str, unsigned int), c, counter);
	else if (c != 0)
	{
		++(*counter);
		ft_putchar(c);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ((*(format + 1)) == ' ' || (*(format
						+ 1)) == '\0'))
			return (-1);
		if (*format != '%')
		{
			counter += ft_putchar(*format);
		}
		else
		{
			ft_format(args, (*(++format)), &counter);
		}
		++(format);
	}
	va_end(args);
	return (counter);
}
