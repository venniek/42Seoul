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
	pthread_mutex_t printing;
	pthread_mutex_t *fork;
	struct timeval starttime;
} t_total;

typedef struct s_phil
{
	int status;
	int id;
	int eat_cnt;
	int left_id;
	int right_id;
	int is_dead;
	pthread_t tid;
	t_total *total;
} t_phil;



//utils.c
int ft_atoi(const char *str);
int get_time(struct timeval nowtime, t_phil phil);

//make_default.c
int make_total(t_total *total, char **av);
int make_total_mutex(t_total *total);
int make_threads(t_total *tot);




//philosophers.c
void *t_function(void *data);




#endif
