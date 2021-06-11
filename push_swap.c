/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:57:11 by naykim            #+#    #+#             */
/*   Updated: 2021/06/03 15:57:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->sorted = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->div = 0;
	stack->order = 0;
	stack->sum = 0;
}

void make_stack(t_stack *stack, int argc, char *argv[])
{
	int i;
	long long tmp;

	stack->cnt = argc;
	stack->a = (int *)malloc(sizeof(int) * argc);
	stack->b = (int *)malloc(sizeof(int) * argc);
	stack->sorted = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(stack, argv[i + 1]);
		if (tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(stack, 1);
		stack->a[argc - i - 1] = tmp;
		stack->sorted[argc - i - 1] = tmp;
		i++;
	}
	selec_sort(stack);
	stack->ai = stack->cnt;
	stack->order = (char **)malloc(sizeof(char *) * 1);
	stack->order[0] = (char *)malloc(sizeof(char) * 5);
}

void push_swap(t_stack *stack)
{
	while (stack->ai > 5)
		a_to_b(stack);
	push_swap_special(stack);
	while (stack->bi > 0)
		b_to_a(stack);
	free(stack->b);
	stack->b = 0;
}

void check_b(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->bi <= 1)
		return ;
	tmp = stack->a[stack->ai - 1];
	i = stack->bi - 1;
	if (tmp < stack->b[0] && tmp > stack->b[i])
		return ;
	while (i > 0 && !(tmp < stack->b[i] && tmp > stack->b[i - 1]))
		i--;
	if (i == 0)
	{
		while (i++ < stack->bi && stack->b[stack->bi - i] > stack->b[stack->bi - i - 1])
			;
		if (i == stack->bi)
			return ;
		if (--i < stack->bi / 2)
		{
			while (i-- >= 0)
				rotate_b(stack);
		}
		else
		{
			while (++i < stack->bi)
				reverse_b(stack);
		}	
	}
	else if (--i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			rotate_b(stack);
	}
	else
	{
		while (i-- >= 0)
			reverse_b(stack);
	}
}

void a_to_b(t_stack *stack)
{
	int pivot;
	int tmp;
	int i;

	tmp = stack->ai;
	pivot = stack->sorted[stack->cnt - (tmp + 1) / 2];
	i = -1;
	while (i++ < tmp && stack->ai >= tmp / 2 + 1)
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
			check_b(stack);
			push_b(stack);
		}
		else
			rotate_a(stack);
	}
	stack->div++;
}

void b_to_a(t_stack *stack)
{
	int i;

	i = stack->bi - 1;
	while (stack->b[i] != stack->sorted[stack->cnt - stack->ai - 1])
			i--;
	if (i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			rotate_b(stack);
	}
	else
	{
		while (i-- >= 0)
			reverse_b(stack);
	}
	i = stack->bi;
	while (stack->bi > 0)
		push_a(stack);
}