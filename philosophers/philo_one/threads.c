
#include "philosophers.h"

void *dead_check(void *data)
{
	t_phil *phils = (t_phil *)data;
	int i;

	while (!phils[0].total->is_dead && phils[0].total->done_cnt != phils[0].total->phil_cnt)
	{
		i = -1;
		while (++i < phils[0].total->phil_cnt && phils[0].total->is_dead == 0)
		{
			if (get_time(phils[i]) - phils[i].last_eat > phils[i].total->time_to_die)
			{
				print_print(phils[i], "is died");
				phils[i].total->is_dead = 1;
				return (NULL);
			}
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
