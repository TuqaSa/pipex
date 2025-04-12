/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:57:21 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/12 19:50:36 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_check(char **argv, int *pipefd)
{
	if (access(argv[1], F_OK) == -1)
	{
		print_error("Error ", argv[1], ": No such file or directory\n");
		close_pipe(pipefd);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		print_error("Error ", argv[1], ": Permission denied\n");
		close_pipe(pipefd);
		exit(EXIT_FAILURE);
	}
}

static void	first_cmd_child(char **argv, int *pipefd, char **envp, t_cmd *cmd1)
{
	file_check(argv, pipefd);
	cmd1->input_fd = open(argv[1], O_RDONLY);
	close(pipefd[0]);
	pipefd[0] = -1;
	if (cmd1->input_fd == -1)
	{
		close_pipe(pipefd);
		print_error("Error ", argv[1], ": Command not found\n");
		exit(1);
	}
	init_cmd(cmd1, argv[2]);
	if (check_cmd(cmd1) == -1)
	{
		clear_cmd(cmd1, 0);
		close(cmd1->input_fd);
		close_pipe(pipefd);
		exit(EXIT_FAILURE);
	}
	execute_cmd(cmd1, cmd1->input_fd, pipefd[1], envp);
}

int	first_cmd_setup(char **argv, int *pipefd, char **envp, t_cmd *cmd1)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	if (pid1 == 0)
		first_cmd_child(argv, pipefd, envp, cmd1);
	return (0);
}

void	init_pipe(int *pipefd, t_cmd *cmd1, t_cmd *cmd2)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	init(cmd1);
	init(cmd2);
}

int	second_cmd(char **argv, int *pipefd, char **envp, t_cmd *cmd2)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		return (-1);
	if (pid2 == 0)
	{
		cmd2->output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd2->output_fd == -1)
		{
			close_pipe(pipefd);
			print_error("Error ", argv[4], ": Command not found\n");
			exit(-1);
		}
		init_cmd(cmd2, argv[3]);
		if (check_cmd(cmd2) == -1)
		{
			clear_cmd(NULL, cmd2);
			close(cmd2->output_fd);
			close_pipe(pipefd);
			exit(EXIT_FAILURE);
		}
		execute_cmd(cmd2, pipefd[0], cmd2->output_fd, envp);
	}
	return (0);
}
