/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:56:48 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:35:47 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 2048

typedef struct	s_stack
{
	int			cnt;
	int			*a;
	int			*b;
	int			*sorted;
	int			ai;
	int			bi;
	int			now;
	int			div;
	int			*pivot;
	char		*last;
}				t_stack;

int				get_next_line(int fd, char **line);
int				read_done(char **line, char **save, int size);
int				update_save(char **save, int index, char **line);
int				ft_newline(const char *save);
void			do_order_checker(t_stack *stack, char *str);

void			default_stack(t_stack *stack);
void			make_stack(t_stack *stack, int argc, char *argv[]);
void			make_div(t_stack *stack);
void			selec_sort(t_stack *stack);

void			swap(t_stack *stack, char c);
void			push(t_stack *stack, char c);
void			rotate(t_stack *stack, char c);
void			reverse(t_stack *stack, char c);
void			do_order(t_stack *stack, char *str);

void			push_back_three(t_stack *stack);
void			push_back_two(t_stack *stack);
void			push_back_to_a(t_stack *stack, int a);

void			sort_a(t_stack *stack);
void			check_a(t_stack *stack);
void			check_a_first(t_stack *stack);
void			rotate_a(t_stack *stack, int i);
int				find_pivot(t_stack *stack);

void			push_swap_under5(t_stack *stack);
void			push_swap_two(t_stack *stack);
void			push_swap_three(t_stack *stack);
void			push_swap_f(t_stack *stack);
void			find_and_push(t_stack *stack, int index, int tmp);

void			push_swap(t_stack *stack);
void			a_to_b_first(t_stack *stack);
void			b_to_a_first(t_stack *stack);
void			a_to_b(t_stack *stack);
void			b_to_a(t_stack *stack);

int				ft_exit(t_stack *stack, int i);
void			ft_intfree(int *num);
void			ft_strfree(char *str);

void			add_one_a(t_stack *stack);
void			swap_stack(int *a, int len);
void			malloc_all(t_stack *stack);

void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				merge_order(t_stack *stack, char *str);
void			print_order(t_stack *stack);
void			new_str(t_stack *stack, char *str);

int				ft_strlen(const char *str);
long long		ft_atoi(t_stack *stack, const char *str, int *k);
long long		make_atoi(t_stack *stack, const char *str, int *i);
int				check_sort(t_stack *stack);
void			sort_sort(int *sort, int len);

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(char *s);
int				ft_strchr(const char *str, int a);
char			*ft_strjoin(char **s1, char *s2);
char			*ft_substr(char *s, int start, size_t len);

#endif
