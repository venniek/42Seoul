#include "philosophers.h"

void *dead_check(void *data)
{
	t_phil *phils = (t_phil *)data;

	while (1)
	{
		if (phils[0].total->done_cnt == phils[0].total->phil_cnt)
		{
			printf("All philosophers are full\n");
			return (NULL);
		}
		if (phils[0].total->is_dead > 0)
		{
			pthread_mutex_lock(&phils[0].total->printing);
			printf("%dms %d is died last_eat: %lld\n", get_time(phils[0]), phils[0].total->is_dead - 1, phils[phils[0].total->is_dead - 1].last_eat);
			pthread_mutex_unlock(&phils[0].total->printing);
			return (NULL);
		}
	}
	return (NULL);
}

void *phil_function(void *data)
{
	t_phil *phil = (t_phil *)data;

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
	return (NULL);
}
