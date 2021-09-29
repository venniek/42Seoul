#include "pipex.h"

void child_process_1(t_var *var, char **env)
{
	int tmp;
	int i = -1;
	int okay = 0;

	close(var->pp[0]);
	tmp = dup2(var->infd, STDIN_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	tmp = dup2(var->pp[1], STDOUT_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	while (var->paths[++i])
	{
		find_cmd(var, i, &var->cmd1[0], &okay);
		if (okay == 1)
			break;
	}
	if (okay == 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		write(STDERR_FILENO, var->cmd1[0], ft_strlen(var->cmd1[0]));
		write(STDERR_FILENO, "command not found", 18);
		ft_exit(127, var);
	}
	if (execve(var->cmd1[0], var->cmd1, env) < 0)
	{
		perror(var->cmd1[0]);
		ft_exit(1, var);
	}
	close(var->pp[1]);
}

void child_process_2(t_var *var, char **env)
{
	int tmp;
	int i = -1;
	int okay = 0;

	close(var->pp[1]);
	tmp = dup2(var->pp[0], STDIN_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	tmp = dup2(var->outfd, STDOUT_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	while (var->paths[++i])
	{
		find_cmd(var, i, &var->cmd2[0], &okay);
		if (okay == 1)
			break;
	}
	if (okay == 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		write(STDERR_FILENO, var->cmd2[0], ft_strlen(var->cmd2[0]));
		write(STDERR_FILENO, "command not found", 18);
		ft_exit(127, var);
	}
	if (execve(var->cmd2[0], var->cmd2, env) < 0)
	{
		perror(var->cmd2[0]);
		ft_exit(1, var);
	}
	close(var->pp[0]);
}

void parent_process(t_var *var, char **env)
{
	int pid2;
	int status;

	pid2 = fork();
	if (pid2 == 0)
		child_process_2(var, env);

}