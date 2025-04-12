/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:57:59 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/12 17:48:40 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(int *pipefd)
{
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (pipefd[1] != -1)
		close(pipefd[1]);
}

void init(t_cmd *cmd)
{
	cmd->input_fd = -1;
	cmd->output_fd = -1;
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	t_cmd	cmd1;
	t_cmd	cmd2;

	check_args(argc, argv);
	init_pipe(pipefd);
	init(&cmd1);
	init(&cmd2);
	if (first_cmd(argv, pipefd, envp, &cmd1) == -1)
	{
		clear_cmd(&cmd1, &cmd2);
		close_pipe(pipefd);
		return (EXIT_FAILURE);
	}
	close(pipefd[1]);
	pipefd[1] = -1;
	if (second_cmd(argv, pipefd, envp, &cmd2) == -1)
	{
		clear_cmd(&cmd1, &cmd2);
		close_pipe(pipefd);
		return (EXIT_FAILURE);
	}
	close(pipefd[0]);
	wait(NULL);
	wait(NULL);
	return (EXIT_SUCCESS);
}
