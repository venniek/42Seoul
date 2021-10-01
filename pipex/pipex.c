#include "pipex.h"

void default_var(t_var *var)
{
	var->infile = 0;
	var->outfile = 0;
	var->paths = 0;
	var->cmd1 = 0;
	var->cmd2 = 0;
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
		child_process(&var, env);
	else
	{
		waitpid(pid, &status, WNOHANG);
//		printf("exit code of child_process: %d\n", WEXITSTATUS(status));
	}
}
