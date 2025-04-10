/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:53:31 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/16 19:19:27 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_freeslices(char **slices)
{
	size_t	i;

	i = 0;
	while (slices[i] != NULL)
		free(slices[i++]);
	free(slices);
}

static int	ft_fill_slices(char **slices, char const *s, char c)
{
	size_t	i;
	size_t	x;

	x = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			slices[x] = ft_substr(s, 0, i);
			if (!slices[x++])
				return (0);
		}
		s += i;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**slices;
	size_t	wordnum;

	wordnum = ft_wordcount(s, c);
	slices = ft_calloc(wordnum + 1, sizeof(char *));
	if (!slices)
		return (NULL);
	if (!ft_fill_slices(slices, s, c))
	{
		ft_freeslices(slices);
		return (NULL);
	}
	return (slices);
}
