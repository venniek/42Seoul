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

long long ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int is_ascending(int *a, int argc);
int	ft_exit(int *a, int *b, int i);

void swap_a(int *a, int *ai);
void swap_b(int *b, int *bi);
void push_a(int *a, int *b, int *ai, int *bi);
void push_b(int *a, int *b, int *ai, int *bi);
void rotate_a(int *a, int *ai);
void rotate_b(int *b, int *bi);
void reverse_a(int *a, int *ai);
void reverse_b(int *b, int *bi);

void push_swap_special(int *a, int *b, int argc);
void push_swap_two(int *a);
void push_swap_three(int *a);
void push_swap_five(int *a, int *b);

void print(int *a, int *b, int argc);

#endif
