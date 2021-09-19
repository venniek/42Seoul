#include "pipex.h"

void default_var(t_var *var)
{
	var->in = 0;
	var->out = 0;
	var->paths = 0;
	var->cmd1 = 0;
	var->cmd2 = 0;
}

int ft_exit(int i, t_var *var)
{
	if (var->in)
	{
		free(var->in);
		var->in = 0;
	}
	if (var->out)
	{
		free(var->out);
		var->out = 0;
	}
	if (var->paths)
	{
		for (int j = 0; var->paths[j]; j++)
		{
			free(var->paths[j]);
			var->paths[j] = 0;
		}
		free(var->paths);
		var->paths = 0;
	}
	if (var->cmd1)
	{
		for (int j = 0; var->cmd1[j]; j++)
		{
			free(var->cmd1[j]);
			var->cmd1[j] = 0;
		}
		free(var->cmd1);
		var->cmd1 = 0;
	}
	if (var->cmd2)
	{
		for (int j = 0; var->cmd2[j]; j++)
		{
			free(var->cmd2[j]);
			var->cmd2[j] = 0;
		}
		free(var->cmd1);
		var->cmd1 = 0;
	}
	if (i == 127)
		strerror(errno);
	exit(i);
}

int main(int ac, char **av, char **env)
{
	t_var var;
	int pid;
	int tmp;

	default_var(&var);
	if (ac != 5)
		ft_exit(1, &var);
	erase_quote(av);
	check_infile_outfile(av, &var);
	var.cmd1 = ft_split(av[2], ' ');
	var.cmd2 = ft_split(av[3], ' ');
	make_paths(env, &var);
	//check_cmd_in_paths(&var);
	pipe(var.pp);
	pid = fork();
	if (pid < 0)
		ft_exit(1, &var);
	if (pid == 0) //child
		child_process_1(&var, env);
	else
	{
		wait(0);
		int pid2 = fork();
		if (pid2 == 0)
			child_process_2(&var, env);
	}
	close(var.outfile);
	close(var.infile);
	exit(0);
}
