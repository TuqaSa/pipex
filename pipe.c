#include "pipex.h"

void	child(char **argv, int *pipefd, char **envp, t_cmd *cmd1)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
	{
		cmd1->input_fd = open(argv[1], O_RDONLY);
		if (cmd1->input_fd == -1)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		close(pipefd[0]);
		execute_cmd(cmd1, cmd1->input_fd, pipefd[1], envp);
	}
}

void	init_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	parnet(char **argv, int *pipefd, char **envp, t_cmd *cmd2)
{
	pid_t   pid2;

	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
	{
		cmd2->output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd2->output_fd == -1)
		{
			perror(argv[4]);
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		execute_cmd(cmd2, pipefd[0], cmd2->output_fd, envp);
	}
}
