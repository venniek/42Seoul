#include "philosophers.h"

void fill_total(t_total *total, char **av)
{
	struct timeval tmp;

	gettimeofday(&tmp, NULL);
	total->starttime = milli_sec(tmp);
	total->is_dead = 0;
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
}

int make_total(t_total *total, char **av)
{
	int i;
	//	fill_total(total, av);
	struct timeval tmp;

	gettimeofday(&tmp, NULL);
	total->starttime = milli_sec(tmp);
	total->is_dead = 0;
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	total->is_done = (int *)malloc(sizeof(int) * total->phil_cnt);
	i = -1;
	while (++i < total->phil_cnt)
		total->is_done[i] = 0;
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
	if (pthread_mutex_init(&total->printing, NULL))
		return (1);
	total->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * total->phil_cnt);
	if (!total->fork)
		return (1);
	while (++i < total->phil_cnt)
	{
		if (pthread_mutex_init(&total->fork[i], NULL))
			return (1);
	}
	return (0);
}

void fill_phil(t_phil *phil, t_total *tot, int i)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	phil->eat_cnt = 0;
	phil->total = tot;
	phil->last_eat = get_time(*phil);
	phil->id = i;
	phil->status = THINK;
	phil->left_fork = (i + tot->phil_cnt - 1) % tot->phil_cnt;
	phil->right_fork = i;
	phil->have_fork = 0;
}

int make_threads(t_total *tot)
{
	t_phil *phils;
	int i;

	phils = (t_phil *)malloc(sizeof(t_phil) * tot->phil_cnt);
	printf("starttime: %lld\n", tot->starttime);
	usleep(3000000);
	if (!phils)
		return (1);
	i = -1;
	while (++i < tot->phil_cnt)
	{
		//		fill_phil(&phils[i], tot, i);
		phils[i].eat_cnt = 0;
		phils[i].total = tot;
		phils[i].last_eat = get_time(phils[i]);
		phils[i].id = i;
		phils[i].status = THINK;
		phils[i].left_fork = (i + tot->phil_cnt - 1) % tot->phil_cnt;
		phils[i].right_fork = i;
		phils[i].have_fork = 0;
		if (pthread_create(&phils[i].tid, NULL, phil_function, (void *)&phils[i]))
			return (1);
	}
	if (pthread_create(&tot->t_dead, NULL, dead_check, (void *)phils))
		return (1);
	pthread_join(tot->t_dead, NULL);
	i = -1;
	while (++i < tot->phil_cnt)
		pthread_join(phils[i].tid, NULL);
	pthread_mutex_destroy(&tot->printing);
	i = -1;
	while (++i < tot->phil_cnt)
		pthread_mutex_destroy(&tot->fork[i]);
	return (0);
}
