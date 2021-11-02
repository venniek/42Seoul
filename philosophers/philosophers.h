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
	int is_dead;
	int *got_fork;
	int starttime;
	int *wait_time;
	pthread_mutex_t printing;
	pthread_mutex_t *fork;

} t_total;

typedef struct s_phil
{
	int status;
	int id; 
	int eat_cnt;
	int left_fork;
	int right_fork;
	int have_fork;
	int last_eat;
	pthread_t tid;
	t_total *total;
} t_phil;



//utils.c
int ft_atoi(const char *str);
int get_time(t_phil phil);

//make_default.c
int make_total(t_total *total, char **av);
int make_total_mutex(t_total *total);
int make_threads(t_total *tot);




//philosophers.c
void *t_function(void *data);
void print_print(t_phil phil, char *str);
int is_first(t_phil *phil);




#endif
