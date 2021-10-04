/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:37:03 by naykim            #+#    #+#             */
/*   Updated: 2021/10/02 15:37:04 by naykim           ###   ########.fr       */
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
	var->cmdchange = 0;
}

void	prepare_everything(t_var *var, int ac, char **av, char **env)
{
	default_var(var);
	if (ac != 5)
		ft_exit(1, var);
	erase_quote(av);
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
	make_paths(env, var);
}

void	erase_quote(char **av)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '\'' || av[i][j] == '\"')
			{
				k = j;
				while (av[i][k + 1])
				{
					av[i][k] = av[i][k + 1];
					k++;
				}
				av[i][k] = '\0';
				j--;
			}
		}
	}
}

void	make_paths(char **env, t_var *var)
{
	int		i;
	int		tmp;
	char	*tmpenv;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strncmp(ft_substr(env[i], 0, 5), "PATH=", 5);
		if (tmp == 0)
		{
			tmpenv = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			var->paths = ft_split(tmpenv, ':');
			break ;
		}
	}
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
