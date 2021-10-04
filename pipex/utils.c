/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:37:54 by naykim            #+#    #+#             */
/*   Updated: 2021/10/02 15:37:54 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_char(char *file)
{
	free(file);
	file = 0;
}

void	free_char_char(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		free(file[i]);
		file[i] = 0;
	}
	file = 0;
}

int	ft_exit(int i, t_var *var)
{
	if (var->infile)
		free_char(var->infile);
	if (var->outfile)
		free_char(var->outfile);
	if (var->paths)
		free_char_char(var->paths);
	if (var->cmd1)
		free_char_char(var->cmd1);
	if (var->cmd2)
		free_char_char(var->cmd2);
	exit(i);
}

void	check_infile(t_var *var, char **av)
{
	var->infile = ft_strdup(av[1]);
	if (access(var->infile, R_OK) < 0)
	{
		write(STDERR_FILENO, "bash: ", 7);
		perror(var->infile);
		close(var->pp[1]);
		ft_exit(1, var);
	}
	else
	{
		var->infd = open(var->infile, O_RDONLY);
		if (var->infd < 0)
		{
			write(STDERR_FILENO, "bash: ", 7);
			perror(var->infile);
			close(var->infd);
			close(var->pp[1]);
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
		close(var->pp[0]);
		ft_exit(1, var);
	}
}
