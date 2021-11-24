/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:08:45 by naykim            #+#    #+#             */
/*   Updated: 2021/11/24 16:08:49 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	only_one_phil(t_total *tot)
{
	if (!tot)
		return ;
	while (get_time(tot) < tot->time_to_die)
		usleep(100);
	printf("%dms 1 died\n", get_time(tot));
}

void	fill_phil(t_phil *phil, t_total *tot, int i)
{
	phil->eat_cnt = 0;
	phil->total = tot;
	phil->last_eat = get_time(phil->total);
	phil->id = i;
	phil->status = THINK;
	phil->left_fork = (i + tot->phil_cnt - 1) % tot->phil_cnt;
	phil->right_fork = i;
}

int	make_threads(t_total *tot)
{
	t_phil	*phils;
	int		i;

	if (tot->phil_cnt == 1)
	{
		only_one_phil(tot);
		pthread_mutex_destroy(&tot->printing);
		pthread_mutex_destroy(&tot->fork[0]);
		return (0);
	}
	phils = (t_phil *)malloc(sizeof(t_phil) * tot->phil_cnt);
	if (!phils)
		return (1);
	i = -1;
	if (make_phil_threads(phils, tot) || make_dead_threads(phils, tot))
		return (1);
	join_threads(phils);
	destroy_mutex(tot, phils);
	if (phils)
	{
		free(phils);
		phils = 0;
	}
	return (0);
}

int	make_phil_threads(t_phil *phils, t_total *tot)
{
	int	i;

	i = -1;
	while (++i < tot->phil_cnt)
	{
		fill_phil(&phils[i], tot, i);
		if (pthread_create(&phils[i].tid, NULL, p_function, (void *)&phils[i]))
			return (1);
	}
	return (0);
}

int	make_dead_threads(t_phil *phils, t_total *tot)
{
	if (pthread_create(&tot->t_dead, NULL, dead_check, (void *)phils))
		return (1);
	return (0);
}
