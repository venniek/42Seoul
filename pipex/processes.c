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

void	close_and_exit(t_var *var, int i, int code)
{
	if (i == 1)
	{
		close(var->infd);
		close(var->pp[1]);
	}
	else
	{
		close(var->outfd);
		close(var->pp[0]);
	}
	ft_exit(code, var);
}

void	origin_cmd(char **cmd)
{
	int	i;
	int	len;

	len = ft_strlen(*cmd);
	i = len - 1;
	while (i >= 0)
	{
		if ((*cmd)[i] == '/')
			break ;
		i--;
	}
	(*cmd) = ft_substr(*cmd, i + 1, len - i);
}

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
		close_and_exit(var, 1, 1);
	if (dup2(var->pp[1], STDOUT_FILENO) < 0)
		close_and_exit(var, 1, 1);
	cmd_check(var, var->cmd1);
	if (execve(var->cmd1[0], var->cmd1, env) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		if (var->cmdchange == 1)
			origin_cmd(&var->cmd1[0]);
		perror(var->cmd1[0]);
		close_and_exit(var, 1, 126);
	}
	close_and_exit(var, 1, 0);
}

void	child_process_2(t_var *var, char **av, char **env)
{
	close(var->pp[1]);
	check_outfile(var, av);
	if (dup2(var->pp[0], STDIN_FILENO) < 0)
		close_and_exit(var, 0, 1);
	if (dup2(var->outfd, STDOUT_FILENO) < 0)
		close_and_exit(var, 0, 1);
	cmd_check(var, var->cmd2);
	if (execve(var->cmd2[0], var->cmd2, env) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		if (var->cmdchange == 1)
			origin_cmd(&var->cmd2[0]);
		perror(var->cmd2[0]);
		close_and_exit(var, 0, 126);
	}
	close_and_exit(var, 0, 1);
}
