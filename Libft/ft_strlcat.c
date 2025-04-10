/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:52:51 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/13 15:14:30 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lsrc;
	size_t	ldst;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (ldst >= size)
		ldst = size;
	if (ldst == size)
		return (size + lsrc);
	if (lsrc < size - ldst)
		ft_memcpy(dst + ldst, src, lsrc + 1);
	else
	{
		ft_memcpy(dst + ldst, src, size - ldst - 1);
		dst[size - 1] = '\0';
	}
	return (ldst + lsrc);
}
