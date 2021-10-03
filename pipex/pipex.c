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
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
	make_paths(env, var);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int		pid;
	int		pid2;
	int		status;

	default_var(&var);
	if (ac != 5)
		ft_exit(1, &var);
	prepare_everything(&var, av, env);
	if (pipe(var.pp) < 0)
		ft_exit(1, &var);
	pid = fork();
	if (pid < 0)
		ft_exit(1, &var);
	if (pid == 0)
		child_process_1(&var, av, env);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			ft_exit(1, &var);
		if (pid2 == 0)
		{
			child_process_2(&var, av, env);
		}
		else
		{
		close(var.pp[0]);
		close(var.pp[1]);
		waitpid(pid2, &status, 0);
		}
	}
	ft_exit(WEXITSTATUS(status), &var);
}
