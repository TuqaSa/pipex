/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:33:29 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/12 17:44:34 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

char	*safe_strdup(const char *s)
{
	char	*dup;

	dup = ft_strdup(s);
	if (!dup)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	return (dup);
}

void	print_error(const char *prefix, const char *message, const char *suffix)
{
	char	buffer[MAX_PATH];
	size_t	len;

	len = 0;
	buffer[0] = '\0';
	if (prefix)
		len += ft_strlcat(buffer + len, prefix, MAX_PATH - len);
	if (message)
		len += ft_strlcat(buffer + len, message, MAX_PATH - len);
	if (suffix)
		len += ft_strlcat(buffer + len, suffix, MAX_PATH - len);
	write(STDERR_FILENO, buffer, ft_strlen(buffer));
}
