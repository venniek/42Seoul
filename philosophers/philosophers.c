#include "philosophers.h"

pthread_mutex_t mutex;
int cnt = 0;



void make_total(t_total *total, char **av)
{
	total->phil_cnt = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		total->cnt_must_eat = ft_atoi(av[5]);
	else
		total->cnt_must_eat = -1;
	
}

void *t_function(void *data)
{
	t_phil *total = (t_phil *)data;
	pthread_mutex_lock(&mutex);
	cnt = total->num;
	printf("num: %d, status: %d\n", total->num, total->status);
	printf("cnt: %d\n", cnt);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main(int ac, char **av)
{
	int i;
	t_total total;

	if (!(ac == 5 || ac == 6))
		exit(0);
	make_total(&total, av);
	printf("phil_cnt: %d\n", total.phil_cnt);
	printf("time_to_die: %d\n", total.time_to_die);
	printf("time_to_eat: %d\n", total.time_to_eat);
	printf("time_to_sleep: %d\n", total.time_to_sleep);
	pthread_mutex_init(&mutex, NULL);
	total.phils = (t_phil *)malloc(sizeof(t_phil) * total.phil_cnt);
	if (!total.phils)
		exit(1);
	i = -1;
	while (++i < total.phil_cnt)
	{
		total.phils[i].num = i + 1;
		total.phils[i].eat_cnt = 0;
		total.phils[i].status = THINK;
		total.tmp = i;
		total.phils[i].tid = pthread_create(&total.phils[i].thread, NULL, t_function, (void *)&total.phils[i]);
		usleep(2000);
	}
	pthread_mutex_destroy(&mutex);
	usleep(2000000);
	return 0;
}