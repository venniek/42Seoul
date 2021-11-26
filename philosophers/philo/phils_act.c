/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:11:28 by naykim            #+#    #+#             */
/*   Updated: 2021/11/26 11:57:38 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	make_phil_eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_lock(&phil->total->fork[phil->right_fork]);
	if (phil->total->is_dead > 0)
	{
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		return ;
	}
	phil->eat_cnt++;
	phil->last_eat = get_time(phil->total);
	print_print(*phil, "has taken a fork");
	print_print(*phil, "has taken a fork");
	print_print(*phil, "is eating");
	phil->status = EAT;
	if (phil->eat_cnt == phil->total->cnt_must_eat)
	{
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		phil->status = DONE;
		// pthread_mutex_lock(*total->done);
		phil->total->done_cnt++;
		// unlock();
	}
}

void	make_phil_sleep(t_phil *phil)
{
	while ((get_time(phil->total) - phil->last_eat) < phil->total->time_to_eat)
	{
		if (phil->total->is_dead > 0)
		{
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
			return ;
		}
		usleep(100);
	}
	pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
	print_print(*phil, "is sleeping");
	phil->status = SLEEP;
}

void	make_phil_think(t_phil *phil)
{
	while ((get_time(phil->total) - phil->last_eat)
		< (phil->total->time_to_eat + phil->total->time_to_sleep))
	{
		if (phil->total->is_dead > 0)
			return ;
		usleep(100);
	}
	print_print(*phil, "is thinking");
	phil->status = THINK;
}
