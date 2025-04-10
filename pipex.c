/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:57:59 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/10 19:31:41 by tsaeed           ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	t_cmd	cmd1;
	t_cmd	cmd2;

	check_args(argc, argv);
	init_pipe(pipefd);
	// init_cmd(&cmd1, argv[2]);
	// if(check_cmd(&cmd1) == -1)
	// {
	// 	clear_cmd(&cmd1, 0);
	// 	close_pipe(pipefd);
	// 	return (EXIT_FAILURE);
	// }
	// init_cmd(&cmd2, argv[3]);
	// if(check_cmd(&cmd2)== -1)
	// {
	// 	clear_cmd(&cmd1, &cmd2);
	// 	close_pipe(pipefd);
	// 	return (EXIT_FAILURE);
	// }
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
	// clear_cmd(&cmd1, &cmd2);
	// close_pipe(pipefd);
	return (EXIT_SUCCESS);
}


// strjoin error messages and put them in one write, output to stderr
