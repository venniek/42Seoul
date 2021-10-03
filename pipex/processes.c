/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:37:10 by naykim            #+#    #+#             */
/*   Updated: 2021/10/02 15:37:12 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_check(t_var *var, char **cmd)
{
	int	i;
	int	okay;

	i = -1;
	okay = 0;
	while (var->paths[++i])
	{
		find_cmd(var, i, &cmd[0], &okay);
		if (okay == 1)
			break ;
	}
	if (okay == 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": command not found\n", 21);
		close(var->pp[0]);
		close(var->pp[1]);
		ft_exit(127, var);
	}
}

void	child_process_1(t_var *var, char **av, char **env)
{
	close(var->pp[0]);
	check_infile(var, av);
	if (dup2(var->infd, STDIN_FILENO) < 0)
	{
		close(var->infd);
		close(var->pp[1]);
		ft_exit(1, var);
	}
	if (dup2(var->pp[1], STDOUT_FILENO) < 0)
	{
		close(var->infd);
		close(var->pp[1]);
		ft_exit(1, var);
	}
	cmd_check(var, var->cmd1);
	if (execve(var->cmd1[0], var->cmd1, env) < 0)
	{
		perror(var->cmd1[0]);
		close(var->infd);
		close(var->pp[1]);
		ft_exit(1, var);
	}
	close(var->infd);
	close(var->pp[1]);
	ft_exit(0, var);
}

void	child_process_2(t_var *var, char **av, char **env)
{
	close(var->pp[1]);
	check_outfile(var, av);
	if (dup2(var->pp[0], STDIN_FILENO) < 0)
	{
		close(var->outfd);
		close(var->pp[0]);
		ft_exit(1, var);
	}
	if (dup2(var->outfd, STDOUT_FILENO) < 0)
	{
		close(var->outfd);
		close(var->pp[0]);
		ft_exit(1, var);
	}
	cmd_check(var, var->cmd2);
	if (execve(var->cmd2[0], var->cmd2, env) < 0)
	{
		perror(var->cmd2[0]);
		close(var->outfd);
		close(var->pp[0]);
		ft_exit(1, var);
	}
	close(var->pp[0]);
	ft_exit(0, var);
}
