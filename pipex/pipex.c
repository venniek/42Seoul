#include "pipex.h"

int ft_exit(int i)
{
	if (i == 1)
		exit(1);
	exit(0);
}

int main(int ac, char **av, char **env)
{
	t_var var;
	int pid;
	int tmp;

	if (ac != 5)
		ft_exit(1);
	erase_quote(av);
	check_infile_outfile(av, &var);
	printf("infile: %s outfile: %s\n", var.in, var.out);
	var.cmd1 = ft_split(av[2], ' ');
	var.cmd2 = ft_split(av[3], ' ');
	make_paths(env, &var);
	check_cmd_in_paths(&var);
	pipe(var.pp);
	pid = fork();
	if (pid < 0)
		ft_exit(1);
			printf("fdinfile: %d, fdoutfile: %d\n", var.fdinfile, var.fdoutfile);

	if (pid == 0) //child
	{
		close(var.pp[0]);
		tmp = dup2(var.fdinfile, STDIN_FILENO);
		tmp = dup2(var.pp[1], STDOUT_FILENO);
		execve(var.cmd1[0], var.cmd1, env);
		close(var.pp[1]);
	}
	else
	{
		wait(0);
		close(var.pp[1]);
		tmp = dup2(var.pp[0], STDIN_FILENO);
		execve(var.cmd2[0], var.cmd2, env);
				tmp = dup2(var.fdoutfile, STDOUT_FILENO);

		close(var.pp[0]);
	}
	close(var.fdoutfile);
	close(var.fdinfile);
	ft_exit(0);
}
