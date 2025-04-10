/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:57:13 by tsaeed            #+#    #+#             */
/*   Updated: 2025/04/10 19:15:02 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd(t_cmd *cmd, const char *cmd_str)
{
	cmd->args = split_command(cmd_str);
	cmd->path = find_command_path(cmd->args[0]);
}

void	clear_cmd(t_cmd *cmd1, t_cmd *cmd2)
{
	if (cmd1)
		cleanup_cmd(cmd1);
	if (cmd2)
		cleanup_cmd(cmd2);
}

void	cleanup_cmd(t_cmd *cmd)
{
	if (cmd->path)
		free(cmd->path);
	if (cmd->args)
		free_args(cmd->args);
	if (cmd->input_fd != -1)
		close(cmd->input_fd);
	if (cmd->output_fd != -1)
		close(cmd->output_fd);
}

int	check_cmd(t_cmd *cmd)
{
	if (cmd->path == NULL)
	{
		// ft_printf("Command not found: %s\n", cmd->args[0]);
		write(2, "Command not found: \n", ft_strlen("Command not found: \n"));
		write(2, cmd->args[0], ft_strlen(cmd->args[0]));
		write(2, "\n", ft_strlen("\n"));
		return (-1);
	}
	return (0);
}

void	execute_cmd(t_cmd *cmd, int in_fd, int out_fd, char **envp)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
		perror("1");
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		perror("2");
	close(in_fd);
	close(out_fd);
	cmd->input_fd = -1;
	cmd->output_fd = -1;
	execve(cmd->path, cmd->args, envp);
	perror("execve");
	cleanup_cmd(cmd);
	exit(EXIT_FAILURE);
}
