/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:09:22 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/13 14:07:47 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	i = 0;
	if (c_dst > c_src)
		while (len--)
			c_dst[len] = c_src[len];
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
