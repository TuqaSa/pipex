/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:57:59 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/05 18:50:28 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	t_cmd	cmd1;
	t_cmd	cmd2;

	check_args(argc, argv);
	init_pipe(pipefd);
	init_cmd(&cmd1, argv[2]);
	check_cmd(&cmd1);
	init_cmd(&cmd2, argv[3]);
	check_cmd(&cmd2);
	child(argv, pipefd, envp, &cmd1);
	parnet(argv, pipefd, envp, &cmd2);
	cleanup_cmd(&cmd1);
	cleanup_cmd(&cmd2);
	return (EXIT_SUCCESS);
}
