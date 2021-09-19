#include "pipex.h"

void child_process_1(t_var *var, char **env)
{
	int tmp;
	int save;
	int i;

	save = dup(STDOUT_FILENO);
	close(var->pp[0]);
	tmp = dup2(var->infile, STDIN_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	tmp = dup2(var->pp[1], STDOUT_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	i = -1;
	while (var->paths[++i])
	{
		if (execve(var->paths[i], var->cmd1, env) > 0)
			break;
		else if (var->paths[i + 1] == 0)
		{
			tmp = dup2(save, STDOUT_FILENO);
			strerror(errno);
			ft_exit(1, var);
		}
	}
	close(var->pp[1]);
}

void child_process_2(t_var *var, char **env)
{
	int tmp;
	int save;

	save = dup(STDOUT_FILENO);
	close(var->pp[1]);
	tmp = dup2(var->pp[0], STDIN_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	tmp = dup2(var->outfile, STDOUT_FILENO);
	if (tmp < 0)
		ft_exit(1, var);
	if (execve(var->cmd2[0], var->cmd2, env) < 0)
	{
		tmp = dup2(save, STDOUT_FILENO);

		strerror(errno);
		ft_exit(1, var);
	}
	close(var->pp[0]);
}