#include "philosophers.h"

void make_phil_eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_lock(&phil->total->fork[phil->right_fork]);
	if (phil->total->is_dead > 0)
	{
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		return;
	}
	phil->status = EAT;
	phil->eat_cnt++;
	phil->last_eat = get_time(*phil);
	print_print(*phil, "has taken a left fork");
	print_print(*phil, "has taken a right fork");
	print_print(*phil, "is eating");
	if (phil->eat_cnt == phil->total->cnt_must_eat)
	{
		pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
		pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		phil->status = DONE;
		phil->total->done_cnt++;
	}
}

void make_phil_sleep(t_phil *phil)
{
	while ((get_time(*phil) - phil->last_eat) < phil->total->time_to_eat)
	{
		if (phil->total->is_dead > 0)
		{
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
			return;
		}
		usleep(100);
	}
	pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
	pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
	print_print(*phil, "is sleeping");
	phil->status = SLEEP;
}

void make_phil_think(t_phil *phil)
{
	while ((get_time(*phil) - phil->last_eat) < (phil->total->time_to_eat + phil->total->time_to_sleep))
	{
		if (phil->total->is_dead > 0)
			return;
		if (get_time(*phil) - phil->last_eat > phil->total->time_to_die)
		{
			phil->total->is_dead = phil->id + 1;
			return;
		}
		usleep(100);
	}
	print_print(*phil, "is thinking");
	phil->status = THINK;
}