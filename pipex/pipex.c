#include "pipex.h"

void default_var(t_var *var)
{
	var->infile = 0;
	var->outfile = 0;
	var->paths = 0;
	var->cmd1 = 0;
	var->cmd2 = 0;
}

int ft_exit(int i, t_var *var)
{
	if (var->infile)
	{
		free(var->infile);
		var->infile = 0;
	}
	if (var->outfile)
	{
		free(var->outfile);
		var->outfile = 0;
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
	exit(i);
}

void prepare_everything(t_var *var, char **av, char **env)
{
	erase_quote(av);
	check_infile_outfile(av, var);
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
	make_paths(env, var);
}

int main(int ac, char **av, char **env)
{
	t_var var;
	int pid;
	int status;

	default_var(&var);
	if (ac != 5)
		ft_exit(1, &var);
	prepare_everything(&var, av, env);
	pipe(var.pp);
	pid = fork();
	if (pid < 0)
		ft_exit(1, &var);
	if (pid == 0)
		child_process_1(&var, env);
	else
	{
		waitpid(pid, &status, WNOHANG);
		parent_process(&var, env);
	}
	close(var.outfd);
	close(var.infd);
	ft_exit(0, &var);
}
