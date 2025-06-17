/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:47:01 by tsaeed            #+#    #+#             */
/*   Updated: 2024/11/21 16:47:37 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str, int *counter);
size_t	ft_numlen(int num);
void	ft_putnbr(int num);
void	ft_putnum(int num, int *counter);
size_t	ft_ptrlen(uintptr_t num);
void	ft_putptr(uintptr_t num);
void	ft_printp(unsigned long long ptr, int *counter);
void	ft_putun(unsigned int num, int *counter);
void	ft_puthex(unsigned int num, const char c);
size_t	ft_hexlen(unsigned int value);
void	ft_printhex(unsigned int value, const char c, int *counter);
void	ft_format(va_list str, char c, int *counter);

#endif
