#include "philosophers.h"

void *t_function(void *data)
{
	t_phil phil = *(t_phil *)data;
	struct timeval now;

	pthread_mutex_lock(&phil.total->printing);

	pthread_mutex_lock(&phil.total->fork[phil.left_id]);
	gettimeofday(&now, NULL);
	printf("%dms %d has taken a left fork #%d\n", get_time(now, phil), phil.id + 1, phil.left_id + 1);
	pthread_mutex_lock(&phil.total->fork[phil.right_id]);
	gettimeofday(&now, NULL);
	printf("%dms %d has taken a right fork #%d\n", get_time(now, phil), phil.id + 1, phil.right_id + 1);
	printf("%dms %d is eating\n", get_time(now, phil), phil.id + 1);
	usleep(phil.total->time_to_eat);
	pthread_mutex_unlock(&phil.total->fork[phil.left_id]);
	pthread_mutex_unlock(&phil.total->fork[phil.right_id]);
	pthread_mutex_unlock(&phil.total->printing);
	gettimeofday(&now, NULL);
	printf("%dms %d is sleeping\n", get_time(now, phil), phil.id + 1);
	usleep(phil.total->time_to_sleep);
	gettimeofday(&now, NULL);
	printf("%dms %d is thinking\n", get_time(now, phil), phil.id + 1);
	return (NULL);
}

int get_time(struct timeval nowtime, t_phil phil)
{
	return (nowtime.tv_usec - phil.total->starttime.tv_usec);
}