#include "philosophers.h"

int make_total(t_total *total, char **av)
{
	gettimeofday(&total->starttime, NULL);
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	if (total->phil_cnt < 0 || total->time_to_die < 0 ||
		total->time_to_eat < 0 || total->time_to_sleep < 0)
		return (1);
	if (av[5])
	{
		total->cnt_must_eat = ft_atoi(av[5]);
		if (total->cnt_must_eat <= 0)
			return (1);
	}
	else
		total->cnt_must_eat = -1;
	if (make_total_mutex(total))
		return (1);
	return (0);
}

int make_total_mutex(t_total *total)
{
	int i;

	i = -1;
	total->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (total->phil_cnt + 1));
	while (++i < total->phil_cnt)
	{
		if (pthread_mutex_init(&total->fork[i], NULL))
			return (1);
	}
	pthread_mutex_init(&total->printing, NULL);
	return (0);
}

int make_threads(t_total *tot)
{
	t_phil *phils;
	int i = 0;

	phils = (t_phil *)malloc(sizeof(t_phil) * tot->phil_cnt);
	while (i < tot->phil_cnt)
	{
		phils[i].is_dead = 0;
		phils[i].eat_cnt = 0;
		phils[i].id = i;
		phils[i].status = THINK;
		phils[i].total = tot;
		phils[i].left_id = (i + tot->phil_cnt - 1) % tot->phil_cnt;
		phils[i].right_id = (i + 1) % tot->phil_cnt;
		if (pthread_create(&phils[i].tid, NULL, t_function, (void *)&phils[i]))
			return (1);

		i++;
	}
	i = -1;
	while (i++ < tot->phil_cnt)
		pthread_join(phils[i].tid, NULL);
	return (0);
}
