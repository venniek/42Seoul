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

void	find_cmd(t_var *var, int i, char **cmd, int *okay)
{
	char	*tmp;

	if (access(*cmd, F_OK) == 0)
	{
		(*okay)++;
		var->cmdchange = 0;
		return ;
	}
	tmp = ft_strdup(var->paths[i]);
	tmp = ft_strjoin(tmp, "/");
	tmp = ft_strjoin(tmp, *cmd);
	if (access(tmp, F_OK) == 0)
	{
		(*okay)++;
		free(*cmd);
		*cmd = tmp;
		var->cmdchange = 1;
	}
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
		ft_exit(127, var);
	}
}

void	check_infile(t_var *var, char **av)
{
	var->infile = ft_strdup(av[1]);
	if (access(var->infile, R_OK) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->infile);
		ft_exit(1, var);
	}
	else
	{
		var->infd = open(var->infile, O_RDONLY);
		if (var->infd < 0)
		{
			write(STDERR_FILENO, "bash: ", 7);
			perror(var->infile);
			ft_exit(1, var);
		}
	}
}

void	check_outfile(t_var *var, char **av)
{
	var->outfile = ft_strdup(av[4]);
	var->outfd = open(var->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (var->outfd < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->outfile);
		ft_exit(1, var);
	}
}
