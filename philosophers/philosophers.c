#include "philosophers.h"

int is_first(t_phil *phil)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (++i < phil->total->phil_cnt)
	{
		if (i == phil->id)
			continue;
		if (phil->last_eat > phil->total->wait_time[i])
			cnt++;
	}
	return (cnt);
}

void *t_function(void *data)
{
	t_phil *phil = (t_phil *)data;
//	int now;
	while (1)
	{
		// if (is_first(&phil) != 0)
		// 	continue;
		if (phil->total->is_dead == 1)
			return (NULL);
		if (get_time(*phil) - phil->last_eat > phil->total->time_to_die)
		{
			print_print(*phil, "died");
			phil->total->is_dead = 1;
			return (NULL);
		}
		if (phil->total->got_fork[phil->left_fork] == 0 && phil->total->got_fork[phil->right_fork] == 0)
		{
			pthread_mutex_lock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_lock(&phil->total->fork[phil->right_fork]);
			print_print(*phil, "has taken a left fork");
			print_print(*phil, "has taken a right fork");
			print_print(*phil, "is eating");
			phil->total->got_fork[phil->right_fork] = 1;
			phil->total->got_fork[phil->left_fork] = 1;
			phil->last_eat = get_time(*phil);
			phil->total->wait_time[phil->id] = phil->last_eat;
			while ((get_time(*phil) - phil->last_eat) < phil->total->time_to_eat)
				usleep(2);
			print_print(*phil, "is sleeping");
			phil->total->got_fork[phil->left_fork] = 0;
			phil->total->got_fork[phil->right_fork] = 0;
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
			while (get_time(*phil) - phil->last_eat < phil->total->time_to_eat + phil->total->time_to_sleep)
				usleep(2);
			print_print(*phil, "is thinking");
		}
	}
	return (NULL);
}

void print_print(t_phil phil, char *str)
{
	pthread_mutex_lock(&phil.total->printing);
	printf("%dms %d %s\n", get_time(phil), phil.id + 1, str);
	pthread_mutex_unlock(&phil.total->printing);
}

int get_time(t_phil phil)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_usec / 1000 - phil.total->starttime);
}