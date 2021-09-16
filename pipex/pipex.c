#include "pipex.h"

int	ft_exit(int i)
{
	if (i == 1)
		exit(1);
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int pid;

	if (ac != 5)
		ft_exit(1);
	erase_quote(av);
	check_infile_outfile(av, &var);
	var.cmd1 = ft_split(av[2], ' ');
	var.cmd2 = ft_split(av[3], ' ');
	make_paths(env, &var);
	check_cmd_in_paths(&var);
	pipe(var.fd);
	pid = fork();
	if (pid < 0)
		ft_exit(1);
	if (pid == 0)   //child
		child_process(&var, env);
	else
		parent_process(&var, env);
	ft_exit(0);
}
