/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:09:20 by naykim            #+#    #+#             */
/*   Updated: 2021/11/24 16:09:25 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_total(t_total *total, char **av)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	total->starttime = milli_sec(tmp);
	total->is_dead = 0;
	total->phil_cnt = (int)ft_atoi(av[1]);
	total->time_to_die = (int)ft_atoi(av[2]);
	total->time_to_eat = (int)ft_atoi(av[3]);
	total->time_to_sleep = (int)ft_atoi(av[4]);
	total->done_cnt = 0;
}

int	make_total(t_total *total, char **av)
{
	fill_total(total, av);
	if (total->phil_cnt <= 0 || total->time_to_die <= 0
		|| total->time_to_eat <= 0 || total->time_to_sleep <= 0)
		return (1);
	if (av[5])
	{
		total->cnt_must_eat = (int)ft_atoi(av[5]);
		if (total->cnt_must_eat <= 0)
			return (1);
	}
	else
		total->cnt_must_eat = -1;
	if (make_total_mutex(total))
		return (1);
	return (0);
}

int	make_total_mutex(t_total *total)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&total->printing, NULL))
		return (1);
	if (pthread_mutex_init(&total->m_done, NULL))
		return (1);
	total->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* total->phil_cnt);
	if (!total->fork)
		return (1);
	while (++i < total->phil_cnt)
	{
		if (pthread_mutex_init(&total->fork[i], NULL))
			return (1);
	}
	return (0);
}
