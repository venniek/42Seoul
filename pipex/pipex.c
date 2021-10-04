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

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int		pid;
	int		status;
	int		status2;

	prepare_everything(&var, ac, av, env);
	if (pipe(var.pp) < 0)
		ft_exit(1, &var);
	pid = fork();
	if (pid < 0)
		ft_exit(1, &var);
	if (pid == 0)
		child_process_1(&var, av, env);
	else
	{
		parent_process(&var, av, env, &status2);
		waitpid(pid, &status, 0);
	}
	ft_exit(WEXITSTATUS(status2), &var);
}
