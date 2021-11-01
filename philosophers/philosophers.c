#include "philosophers.h"

void *t_function(void *data)
{
	t_phil phil = *(t_phil *)data;
	int now;
	if (phil.total->is_dead == 1)
		return (NULL);
	while (1)
	{
		if (phil.total->got_fork[phil.left_fork] == 0 && phil.total->got_fork[phil.right_fork] == 0)
		{
			pthread_mutex_lock(&phil.total->fork[phil.left_fork]);
			phil.total->got_fork[phil.left_fork] = 1;
			pthread_mutex_lock(&phil.total->fork[phil.right_fork]);
			phil.total->got_fork[phil.right_fork] = 1;
			now = get_time(phil);
			print_print(now, phil);
			phil.last_eat = now;
			while (1)
			{
				if ((get_time(phil) - phil.last_eat) > phil.total->time_to_eat)
				{
					printf("%dms %d is sleeping\n", get_time(phil), phil.id + 1);
					break;
				}
				usleep(1);
			}
			phil.total->got_fork[phil.left_fork] = 0;
			phil.total->got_fork[phil.right_fork] = 0;
			pthread_mutex_unlock(&phil.total->fork[phil.left_fork]);
			pthread_mutex_unlock(&phil.total->fork[phil.right_fork]);
			while (1)
			{
				if ((get_time(phil) - phil.last_eat) > phil.total->time_to_eat + phil.total->time_to_sleep)
				{
					printf("%dms %d is thinking\n", get_time(phil), phil.id + 1);
					break;
				}
				usleep(2);
			}
		}
		if (get_time(phil) > 2000)
			return NULL;
	}
	return (NULL);
}

void print_print(int now, t_phil phil)
{
	pthread_mutex_lock(&phil.total->printing);
	printf("%dms %d has taken a left fork #%d\n", now, phil.id + 1, phil.left_fork + 1);
	printf("%dms %d has taken a right fork #%d\n", now, phil.id + 1, phil.right_fork + 1);
	printf("%dms %d is eating\n", now, phil.id + 1);
	pthread_mutex_unlock(&phil.total->printing);
}

int get_time(t_phil phil)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_usec - phil.total->starttime.tv_usec);
}