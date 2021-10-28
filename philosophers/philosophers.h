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

typedef struct s_phil
{
	pthread_t thread;
	int tid;
	int status;
	int num;
	int eat_cnt;
} t_phil;

typedef struct s_total
{
	int phil_cnt;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int cnt_must_eat;
	int tmp;
	t_phil *phils;
} t_total;



//utils.c
int ft_atoi(const char *str);


//philo.c





#endif
