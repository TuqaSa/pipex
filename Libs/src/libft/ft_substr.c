/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:58:34 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/13 17:35:09 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lstr;
	char	*str;

	if (s == NULL)
		return (NULL);
	lstr = ft_strlen(s);
	if (start >= lstr)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	if (len > lstr - start)
		len = lstr - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	str[len] = '\0';
	return (str);
}
