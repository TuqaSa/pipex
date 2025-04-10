#include "pipex.h"

void	init_cmd(t_cmd *cmd, const char *cmd_str)
{
	cmd->args = split_command(cmd_str);
	cmd->path = find_command_path(cmd->args[0]);
	cmd->input_fd = -1;
	cmd->output_fd = -1;
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

void	check_cmd(t_cmd *cmd)
{
	if (cmd->path == NULL)
	{
		printf("Command not found: %s\n", cmd->args[0]);
		cleanup_cmd(cmd);
		exit(EXIT_FAILURE);
	}
}

void	execute_cmd(t_cmd *cmd, int in_fd, int out_fd, char **envp)
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	if (cmd->input_fd != -1)
		close(cmd->input_fd);
	if (cmd->output_fd != -1)
		close(cmd->output_fd);
	execve(cmd->path, cmd->args, envp);
	perror("execve");
	cleanup_cmd(cmd);
	exit(EXIT_FAILURE);
}
