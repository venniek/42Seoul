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
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp == -1 || tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(stack, 1);
		stack->a[argc - i - 1] = tmp;
		i++;
	}
	stack->ai = stack->cnt;
	stack->order = (char **)malloc(sizeof(char *) * 1);
	stack->order[0] = (char *)malloc(sizeof(char) * 5);
}


int make_sorted(t_stack *stack, int *sorted)
{
	int i;

	i = -1;
	while (++i < stack->cnt)
		sorted[i] = stack->a[i];
	return (selec_sort(sorted, stack));
}

void push_swap(t_stack *stack)
{
//	int i;

//	while (stack->ai > 5)
//		a_to_b(stack);
	push_swap_special(stack);
//	while (stack->bi > 0)
//		b_to_a(stack);
}
/*
void check_b(t_stack *stack)
{

}
*/
void a_to_b(t_stack *stack)
{
	int *sorted;
	int pivot;
	int i;

	sorted = (int *)malloc(sizeof(int) * stack->cnt / ft_pow(2, stack->div));
	pivot = make_sorted(stack, sorted);
	i = -1;
	while (++i < stack->ai)
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
//			check_b(stack);
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

	if (stack->ai <= 5)
	{
		i = -1;
		while (++i < stack->ai)
		{

			push_a(stack);
		}	
		push_swap_special(stack);
	}
	else
	{
		
	}
	
}