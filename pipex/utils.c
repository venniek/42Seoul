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
	if (var->infd > 0)
		close(var->infd);
	if (var->outfd > 0)
		close(var->outfd);
	if (var->pp[0] > 0)
		close(var->pp[0]);
	if (var->pp[1] > 0)
		close(var->pp[1]);
	exit(i);
}
