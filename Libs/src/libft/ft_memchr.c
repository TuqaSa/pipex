/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:17:37 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/07 15:50:20 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*big;
	size_t			i;

	big = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (big[i] == (unsigned char)c)
			return ((void *)&big[i]);
		i++;
	}
	return (NULL);
}
