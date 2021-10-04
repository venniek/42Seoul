/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:00:54 by naykim            #+#    #+#             */
/*   Updated: 2021/10/04 17:00:58 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_1(t_var *var, char **av, char **env)
{
	close(var->pp[0]);
	check_infile(var, av);
	if (dup2(var->infd, STDIN_FILENO) < 0)
		ft_exit(1, var);
	if (dup2(var->pp[1], STDOUT_FILENO) < 0)
		ft_exit(1, var);
	cmd_check(var, var->cmd1);
	if (execve(var->cmd1[0], var->cmd1, env) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		if (var->cmdchange == 1)
			origin_cmd(&var->cmd1[0]);
		perror(var->cmd1[0]);
		ft_exit(126, var);
	}
	ft_exit(0, var);
}

void	child_process_2(t_var *var, char **av, char **env)
{
	close(var->pp[1]);
	check_outfile(var, av);
	if (dup2(var->pp[0], STDIN_FILENO) < 0)
		ft_exit(1, var);
	if (dup2(var->outfd, STDOUT_FILENO) < 0)
		ft_exit(1, var);
	cmd_check(var, var->cmd2);
	if (execve(var->cmd2[0], var->cmd2, env) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		if (var->cmdchange == 1)
			origin_cmd(&var->cmd2[0]);
		perror(var->cmd2[0]);
		ft_exit(126, var);
	}
	ft_exit(0, var);
}

void	parent_process(t_var *var, char **av, char **env, int *status2)
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
		ft_exit(1, var);
	if (pid2 == 0)
		child_process_2(var, av, env);
	else
	{
		close(var->pp[0]);
		close(var->pp[1]);
		waitpid(pid2, status2, 0);
	}
}
