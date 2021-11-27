/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:11:38 by naykim            #+#    #+#             */
/*   Updated: 2021/11/26 09:46:32 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_phil *phils)
{
	int	i;

	pthread_join(phils->total->t_dead, NULL);
	i = -1;
	while (++i < phils->total->phil_cnt)
		pthread_join(phils[i].tid, NULL);
}

void	destroy_mutex(t_total *tot, t_phil *phils)
{
	int	i;

	pthread_mutex_destroy(&tot->printing);
	pthread_mutex_destroy(&tot->m_done);
	i = -1;
	while (++i < tot->phil_cnt)
	{
		pthread_mutex_destroy(&tot->fork[i]);
		phils[i].total = 0;
	}
}

void	*p_function(void *data)
{
	t_phil	*phil;

	phil = (t_phil *)data;
	if (phil->id % 2 == 0)
		usleep(phil->total->time_to_eat * 100);
	while (!phil->total->is_dead && phil->status != DONE)
	{
		if (phil->status == THINK)
			make_phil_eat(phil);
		else if (phil->status == EAT)
			make_phil_sleep(phil);
		else if (phil->status == SLEEP)
			make_phil_think(phil);
	}
	pthread_mutex_lock(&phil->total->m_done);
	if (phil->total->done_cnt == phil->total->phil_cnt)
	{
		pthread_mutex_lock(&phil->total->printing);
		printf("All philosophers have eaten enough\n");
		pthread_mutex_unlock(&phil->total->printing);
	}
	pthread_mutex_unlock(&phil->total->m_done);
	return (NULL);
}

void	*dead_check(void *data)
{
	t_phil	*phils;
	t_total	*total;
	int		i;

	phils = (t_phil *)data;
	total = phils[0].total;
	while (!total->is_dead && total->done_cnt != total->phil_cnt)
	{
		i = -1;
		while (++i < total->phil_cnt && total->is_dead == 0)
		{
			if (get_time(phils[i].total) - phils[i].last_eat
				> total->time_to_die)
			{
				pthread_mutex_lock(&total->printing);
				printf("%d %d died", get_time(total), phils[i].id + 1);
				total->is_dead = 1;
				pthread_mutex_unlock(&total->printing);
				return (NULL);
			}
		}
	}
	return (NULL);
}
