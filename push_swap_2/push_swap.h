/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:56:48 by naykim            #+#    #+#             */
/*   Updated: 2021/06/03 15:56:53 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>


typedef struct s_stack
{
	int cnt;
	int *a;
	int *b;
	int *sorted;
	int ai;
	int bi;
	int div;
} t_stack;

long long ft_atoi(t_stack *stack, const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_strcmp(const char *s1, const char *s2);

int ft_pow(int a, int b);
int is_ascending(t_stack *stack);
int	ft_exit(t_stack *stack, int i);
void ft_free(char **str, int cnt);
void print_order(char *str);

void swap(t_stack *stack, char c);
void push(t_stack *stack, char c);
void rotate(t_stack *stack, char c);
void reverse(t_stack *stack, char c);
void do_order(t_stack *stack, char *str);

void push_swap_special(t_stack *stack);
void push_swap_two(t_stack *stack);
void push_swap_three(t_stack *stack);
void push_swap_f(t_stack *stack);

void find_and_push(t_stack *stack, int index, int tmp);
void push_swap(t_stack *stack);
void a_to_b(t_stack *stack);
void b_to_a(t_stack *stack);
void check_a(t_stack *stack);

void default_stack(t_stack *stack);
void make_stack(t_stack *stack, int argc, char *argv[]);
int selec_sort(t_stack *stack);

#endif
