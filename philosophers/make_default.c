#include "philosophers.h"

int make_total(t_total *total, char **av)
{
	int i;

	gettimeofday(&total->starttime, NULL);
	total->is_dead = 0;
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	total->wait_time = (int *)malloc(sizeof(int) * total->phil_cnt);
	i = -1;
	while (++i < total->phil_cnt)
		total->wait_time[i] = 0;
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
	pthread_mutex_init(&total->printing, NULL);
	total->got_fork = (int *)malloc(sizeof(int) * total->phil_cnt);
	total->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * total->phil_cnt);
	while (++i < total->phil_cnt)
	{
		total->got_fork[i] = 0;
		if (pthread_mutex_init(&total->fork[i], NULL))
			return (1);
	}
	return (0);
}

int make_threads(t_total *tot)
{
	t_phil *phils;
	int i = 0;

	phils = (t_phil *)malloc(sizeof(t_phil) * tot->phil_cnt);
	while (i < tot->phil_cnt)
	{
		struct timeval now;
		gettimeofday(&now, NULL);
		phils[i].eat_cnt = 0;
		phils[i].last_eat = (now.tv_usec - tot->starttime.tv_usec) / 1000;
		phils[i].id = i;
		phils[i].status = THINK;
		phils[i].total = tot;
		phils[i].left_fork = (i + tot->phil_cnt - 1) % tot->phil_cnt;
		phils[i].right_fork = i;
		phils[i].have_fork = 0;
		if (pthread_create(&phils[i].tid, NULL, t_function, (void *)&phils[i]))
			return (1);

		i++;
	}
	
	printf("is_dead: %d\n", tot->is_dead);
	i = -1;
	while (++i < tot->phil_cnt)
		pthread_join(phils[i].tid, NULL);
	pthread_mutex_destroy(&tot->printing);
	i = -1;
	while (++i < tot->phil_cnt)
		pthread_mutex_destroy(&tot->fork[i]);
	return (0);
}
