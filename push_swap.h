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
# include <stdio.h>     //delete it!!!!!!!!!!!!!!!

typedef struct s_stack
{
	int cnt;
	int *a;
	int *b;
	int ai;
	int bi;
	char **order;
	int sum;
} t_stack;

long long ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_stradd(t_stack *stack, char *str);
void	ft_strcpy(char *dest, char *src);

int is_ascending(t_stack *stack);
int	ft_exit(t_stack *stack, int i);
void ft_free(char **str, int cnt);
void add_order(t_stack *stack, char *str);

void swap_a(t_stack *stack);
void swap_b(t_stack *stack);
void push_a(t_stack *stack);
void push_b(t_stack *stack);
void rotate_a(t_stack *stack);
void rotate_b(t_stack *stack);
void reverse_a(t_stack *stack);
void reverse_b(t_stack *stack);

void push_swap_special(t_stack *stack);
void push_swap_two(t_stack *stack);
void push_swap_three(t_stack *stack);
void push_swap_five(t_stack *stack);

void print(t_stack *stack); ///delete it!!!! using printf
void default_stack(t_stack *stack);
void make_stack(t_stack *stack, int argc, char *argv[]);

#endif
