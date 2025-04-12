/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:07:23 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/12 16:37:34 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define MAX_PATH 1024
# define MAX_ARGS 64

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	**args;
	char	*path;
	int		input_fd;
	int		output_fd;
}			t_cmd;

char		**split_command(const char *cmd);
char		*find_command_path(const char *cmd);
void		clear_cmd(t_cmd *cmd1, t_cmd *cmd2);
void		free_tokens(char **tokens);
void		free_args(char **args);
void		check_args(int argc, char **argv);
void		init_cmd(t_cmd *cmd, const char *cmd_str);
void		cleanup_cmd(t_cmd *cmd);
int			check_cmd(t_cmd *cmd);
void		execute_cmd(t_cmd *cmd, int in_fd, int out_fd, char **envp);
void		init_pipe(int *pipefd);
int			first_cmd(char **argv, int *pipefd, char **envp, t_cmd *cmd1);
int			second_cmd(char **argv, int *pipefd, char **envp, t_cmd *cmd2);
void		close_pipe(int *pipefd);
void		*safe_malloc(size_t size);
char		*safe_strdup(const char *s);
void		print_error(const char *prefix, const char *message,
				const char *suffix);

#endif
