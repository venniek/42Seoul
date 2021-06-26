/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:56:48 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:40:08 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

long long		ft_atoi(t_stack *stack, const char *str);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				check_sort(t_stack *stack);

int				ft_exit(t_stack *stack, int i);
void			ft_intfree(int *num);
void			ft_strfree(char *str);
void			sort_sort(int *sort, int len);
int				merge_order(t_stack *stack, char *str);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(const char *str);
char			*ft_strdup(char *s);
int				ft_strchr(const char *str, int a);

void			swap(t_stack *stack, char c);
void			push(t_stack *stack, char c);
void			rotate(t_stack *stack, char c);
void			reverse(t_stack *stack, char c);
void			do_order(t_stack *stack, char *str);

void			push_swap_under5(t_stack *stack);
void			push_swap_two(t_stack *stack);
void			push_swap_three(t_stack *stack);
void			push_swap_f(t_stack *stack);
void			find_and_push(t_stack *stack, int index, int tmp);

void			push_back_three(t_stack *stack);
void			push_back_two(t_stack *stack);
void			push_back_to_a(t_stack *stack, int a);

void			push_swap(t_stack *stack);
void			push_swap_first(t_stack *stack);
void			a_to_b(t_stack *stack);
void			b_to_a(t_stack *stack);
void			b_to_a_first(t_stack *stack);

void			sort_a(t_stack *stack);
void			check_a(t_stack *stack);
void			check_a_first(t_stack *stack);
void			rotate_a(t_stack *stack, int i);
int				find_pivot(t_stack *stack);

void			default_stack(t_stack *stack);
void			make_stack(t_stack *stack, int argc, char *argv[]);
void			make_div(t_stack *stack);
void			selec_sort(t_stack *stack);

#endif
