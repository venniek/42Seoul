/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:11:00 by naykim            #+#    #+#             */
/*   Updated: 2021/11/16 18:11:04 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define THINK 0
# define EAT 1
# define SLEEP 2
# define DONE 3

typedef struct s_total
{
	int				phil_cnt;
	int				cnt_must_eat;
	int				is_dead;
	int				done_cnt;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		starttime;
	pthread_t		t_dead;
	pthread_mutex_t	printing;
	pthread_mutex_t	*fork;
}	t_total;

typedef struct s_phil
{
	int			id;
	int			status;
	int			eat_cnt;
	int			left_fork;
	int			right_fork;
	long long	last_eat;
	pthread_t	tid;
	t_total		*total;
}	t_phil;

int			free_and_end(t_total *total, int i);

void		fill_total(t_total *total, char **av);
int			make_total(t_total *total, char **av);
int			make_total_mutex(t_total *total);

void		only_one_phil(t_total *tot);
void		fill_phil(t_phil *phil, t_total *tot, int i);
int			make_threads(t_total *tot);
int			make_phil_threads(t_phil *phils, t_total *tot);
int			make_dead_threads(t_phil *phils, t_total *tot);

void		make_phil_eat(t_phil *phil);
void		make_phil_sleep(t_phil *phil);
void		make_phil_think(t_phil *phil);

void		join_threads(t_phil *phils);
void		destroy_mutex(t_total *tot, t_phil *phils);
void		*p_function(void *data);
void		*dead_check(void *data);

long long	ft_atoi(const char *str);
long long	milli_sec(struct timeval time);
int			get_time(t_total *total);
void		print_print(t_phil phil, char *str);

#endif
