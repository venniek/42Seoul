/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:36:55 by naykim            #+#    #+#             */
/*   Updated: 2021/10/02 15:36:58 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	default_var(t_var *var)
{
	var->infile = 0;
	var->outfile = 0;
	var->paths = 0;
	var->cmd1 = 0;
	var->cmd2 = 0;
}

void	prepare_everything(t_var *var, char **av, char **env)
{
	erase_quote(av);
	check_infile_outfile(av, var);
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
	make_paths(env, var);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int		pid;
	int		status;
	int		pid2;
	int		status2;

	default_var(&var);
	if (ac != 5)
		ft_exit(1, &var);
	prepare_everything(&var, av, env);
	pipe(var.pp);
	pid = fork();
	if (pid < 0)
		ft_exit(1, &var);
	if (pid == 0)
	{
		pid2 = fork();
		if (pid2 == 0)
			child_process_1(&var, env);
		else
		{
			waitpid(pid2, &status2, WNOHANG);
			if (WIFEXITED(status2) == 0)
				ft_exit(-1, &var);
			child_process_2(&var, env);
		}
	}
	else
		waitpid(pid, &status, WNOHANG);
}
