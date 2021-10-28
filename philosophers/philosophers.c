#include "philosophers.h"

pthread_mutex_t mutex;
int cnt = 0;

int make_total(t_total *total, char **av)
{
	gettimeofday(&total->starttime, NULL);
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		total->cnt_must_eat = ft_atoi(av[5]);
	else
		total->cnt_must_eat = -1;
	if (total->phil_cnt < 0 || total->time_to_die < 0 ||
		total->time_to_eat < 0 || total->time_to_sleep < 0)
		return (1);
	return (0);
}

void *t_function(void *data)
{
	t_phil phil = *(t_phil *)data;
	struct timeval nowtime;

	pthread_mutex_lock(phil.mutex);
	gettimeofday(&nowtime, NULL);
	printf("time: %d\n", nowtime.tv_usec - phil.total.starttime.tv_usec);
	pthread_mutex_unlock(phil.mutex);
	return (NULL);
}

int make_threads(t_total tot)
{
	t_phil *phils;
	int i = 0;
	pthread_mutex_t tmp_mutex;

	phils = (t_phil *)malloc(sizeof(t_phil) * tot.phil_cnt);
	pthread_mutex_init(&mutex, NULL);
	while (i < tot.phil_cnt)
	{
		phils[i].mutex = &tmp_mutex;
		phils[i].eat_cnt = 0;
		phils[i].num = i + 1;
		phils[i].status = THINK;
		phils[i].total = tot;
		if (pthread_create(&phils[i].tid, NULL, t_function, (void *)&phils[i]))
			return (1);

		i++;
	}
	i = 0;
	while (i < tot.phil_cnt)
	{
		pthread_join(phils[i].tid, NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}

int main(int ac, char **av)
{
	t_total total;

	if (!(ac == 5 || ac == 6))
		exit(0);
	if (make_total(&total, av))
		return (1);
	if (make_threads(total))
		return (1);
	usleep(2000000);

	return 0;
}