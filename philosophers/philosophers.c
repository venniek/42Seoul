#include "philosophers.h"

void *dead_check(void *data)
{
	t_phil *phils = (t_phil *)data;
	int i;

	if (phils[0].total->is_dead == 1)
		return NULL;
	while (!phils[0].total->is_dead)
	{
		i = -1;
		int tmp = 0;
		while (++i < phils[0].total->phil_cnt)
		{
			if (phils[i].status == THINK && get_time(phils[i]) - phils[i].last_eat > phils[i].total->time_to_die)
			{
				pthread_mutex_lock(&phils[i].total->printing);
				printf("%lldms %d is died\n", get_time(phils[i]), phils[i].id + 1);
				phils[i].total->is_dead = 1;
				pthread_mutex_unlock(&phils[0].total->printing);
				break;
			}
			if (phils[i].total->is_done[i] == 1)
				tmp++;
		}
		if (tmp == phils[0].total->phil_cnt)
		{
			printf("All phils eat enough\n");
			return (NULL);
		}
	}
	return (NULL);
}

void *phil_function(void *data)
{
	t_phil *phil = (t_phil *)data;

	if (phil->id % 2 == 0)
		usleep(phil->total->time_to_eat * 1000);
	while (!phil->total->is_dead && phil->status != DONE)
	{
		if (phil->status == THINK)
			make_phil_eat(phil);
		else if (phil->status == EAT)
			make_phil_sleep(phil);
		else if (phil->status == SLEEP)
			make_phil_think(phil);
	}
	return (NULL);
}
