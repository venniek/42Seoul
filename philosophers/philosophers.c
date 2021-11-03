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
		{
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
			break;
		}
		if (get_time(*phil) - phil->last_eat > phil->total->time_to_die)
		{
			print_print(*phil, "died");
			phil->total->is_dead = 1;
			break ;
		}
		if (phil->status == THINK && phil->total->got_fork[phil->left_fork] == 0 && phil->total->got_fork[phil->right_fork] == 0)
		{
			pthread_mutex_lock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_lock(&phil->total->fork[phil->right_fork]);
			print_print(*phil, "has taken a left fork");
			print_print(*phil, "has taken a right fork");
			print_print(*phil, "is eating");
			phil->total->got_fork[phil->right_fork] = 1;
			phil->total->got_fork[phil->left_fork] = 1;
			phil->status = EAT;
			phil->last_eat = get_time(*phil);
			phil->total->wait_time[phil->id] = phil->last_eat;
		}
		else if (phil->status == EAT)
		{
			while ((get_time(*phil) - phil->last_eat) < phil->total->time_to_eat)
			{
				printf("now: %dms eat more\n", get_time(*phil));	usleep(2000); }
			print_print(*phil, "is sleeping");
			phil->status = SLEEP;
			phil->total->got_fork[phil->left_fork] = 0;
			phil->total->got_fork[phil->right_fork] = 0;
			pthread_mutex_unlock(&phil->total->fork[phil->left_fork]);
			pthread_mutex_unlock(&phil->total->fork[phil->right_fork]);
		}
		else if (phil->status == SLEEP)
		{
			while ((get_time(*phil) - phil->last_eat) < (phil->total->time_to_eat + phil->total->time_to_sleep))
			{
				printf("sleep more\n");	usleep(2000); }
			print_print(*phil, "is thinking");
			phil->status = THINK;
		}
	}
	return (NULL);
}

void print_print(t_phil phil, char *str)
{
//	pthread_mutex_lock(&phil.total->printing);
	printf("%dms %d %s\n", get_time(phil), phil.id + 1, str);
//	pthread_mutex_unlock(&phil.total->printing);
}

int get_time(t_phil phil)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	printf("now: %d, starttime: %d\n", now.tv_usec / 1000, phil.total->starttime.tv_usec /1000);
	return ((now.tv_sec - ) + .tv_usec - phil.total->starttime.tv_usec) / 1000);
}
