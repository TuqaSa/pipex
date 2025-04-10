/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:57:18 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/10 18:34:49 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

char	**split_command(const char *cmd)
{
	char	**args;
	char	cmd_copy[MAX_PATH];
	char	**tokens;
	int		i;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (!args)
		exit(EXIT_FAILURE);
	ft_strlcpy(cmd_copy, cmd, MAX_PATH);
	tokens = ft_split(cmd_copy, ' ');
	if (!tokens)
		exit(EXIT_FAILURE);
	i = 0;
	while (tokens[i] != NULL && i < MAX_ARGS - 1)
	{
		args[i] = strdup(tokens[i]);
		if (!args[i])
			exit(EXIT_FAILURE);
		i++;
	}
	args[i] = NULL;
	free_tokens(tokens);
	return (args);
}

char	*find_command_path(const char *cmd)
{
	char		*result;
	int			i;
	const char	*paths[] = {"/bin/", "/usr/bin/", "/usr/local/bin/", NULL};
	if(cmd == NULL)
		return(NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	result = malloc(MAX_PATH);
	if (!result)
		exit(EXIT_FAILURE);
	i = 0;
	while (paths[i] != NULL)
	{
		result[0] = '\0';
		ft_strlcpy(result, paths[i], MAX_PATH);
		ft_strlcat(result, cmd, MAX_PATH);
		if (access(result, X_OK) == 0)
			return (result);
		i++;
	}
	free(result);
	return (NULL);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 5)
	{
		write(STDERR_FILENO, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(EXIT_FAILURE);
	}
	// if (access(argv[1], F_OK) == -1)
	// {
	// 	ft_printf("%s : No such file or directory\n", argv[1]);
	// 	exit(EXIT_FAILURE);
	// }
	// if (access(argv[1], R_OK) == -1)
	// {
	// 	ft_printf("%s : Permission denied\n", argv[1]);
	// 	exit(EXIT_FAILURE);
	// }
}
