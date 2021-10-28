#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/time.h>

# define THINK 0
# define EAT 1
# define SLEEP 2

typedef struct s_total
{
	int phil_cnt;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int cnt_must_eat;
	int tmp;
	struct timeval starttime;
} t_total;

typedef struct s_phil
{
	int status;
	int num;
	int eat_cnt;
	pthread_mutex_t *mutex;
	pthread_t tid;
	t_total total;
} t_phil;



//utils.c
int ft_atoi(const char *str);


//philo.c
int make_total(t_total *total, char **av);
void *t_function(void *data);
int make_threads(t_total tot);




#endif
