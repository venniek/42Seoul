#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	atoi;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * atoi);
}

long long milli_sec(struct timeval time)
{
	return ((time.tv_sec * 1000000 + time.tv_usec) / 1000);
}



void print_print(t_phil phil, char *str)
{
	pthread_mutex_lock(&phil.total->printing);
	if (phil.total->is_dead == 1)
	{
		pthread_mutex_unlock(&phil.total->printing);
		return ;
	}
	printf("%lldms %d %s\n", get_time(phil), phil.id + 1, str);
	pthread_mutex_unlock(&phil.total->printing);
}

long long get_time(t_phil phil)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (milli_sec(now) - phil.total->starttime);
}
