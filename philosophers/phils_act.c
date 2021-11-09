#include "philosophers.h"

void make_phil_eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_lock(&phil->total->fork[phil->right_fork]);
	if (phil->total->is_dead == 1)
	{
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		return;
	}
	print_print(*phil, "has taken a left fork");
	print_print(*phil, "has taken a right fork");
	print_print(*phil, "is eating");
	phil->status = EAT;
	phil->eat_cnt++;
	phil->last_eat = get_time(*phil);
	if (phil->eat_cnt == phil->total->cnt_must_eat)
	{
		phil->status = DONE;
		phil->total->is_done[phil->id] = 1;
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		return;
	}
}

void make_phil_sleep(t_phil *phil)
{
	while ((get_time(*phil) - phil->last_eat) < phil->total->time_to_eat)
	{
		if (phil->total->is_dead == 1)
		{
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
			return;
		}
		usleep(2);
	}
	print_print(*phil, "is sleeping");
	phil->status = SLEEP;
	pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
}

void make_phil_think(t_phil *phil)
{
	while ((get_time(*phil) - phil->last_eat) < (phil->total->time_to_eat + phil->total->time_to_sleep))
	{
		if (phil->total->is_dead == 1)
			return;
		usleep(2);
	}
	print_print(*phil, "is thinking");
	phil->status = THINK;
}