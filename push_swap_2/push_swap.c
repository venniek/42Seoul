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
}

void push_swap(t_stack *stack)
{
	while (stack->ai > 5)
		a_to_b(stack);
	push_swap_special(stack);
	while (stack->bi > 0)
		b_to_a(stack);
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
				do_order(stack, "rb");
		}
		else
		{
			while (++i < stack->bi)
				do_order(stack, "rrb");
		}	
	}
	else if (--i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			do_order(stack, "rb");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rrb");
	}
}

void check_a(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->ai <= 1)
		return ;
	tmp = stack->b[stack->bi - 1];
	i = stack->ai - 1;
	if (tmp > stack->a[0] && tmp < stack->a[i])
		return ;
	while (i > 0 && !(tmp > stack->b[i] && tmp < stack->b[i - 1]))
		i--;
	if (i == 0)
	{
		while (i++ < stack->ai && stack->a[stack->ai - i] < stack->a[stack->ai - i - 1])
			;
		if (i == stack->ai)
			return ;
		if (--i < stack->ai / 2)
		{
			while (i-- >= 0)
				do_order(stack, "ra");
		}
		else
		{
			while (++i < stack->ai)
				do_order(stack, "rra");
		}	
	}
	else if (--i >= stack->ai / 2)
	{
		while (++i < stack->ai)
			do_order(stack, "ra");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rra");
	}
}


void a_to_b(t_stack *stack)
{
	int pivot1;
	int pivot2;
	int tmp;
	int i;

	tmp = stack->ai;
	pivot1 = stack->sorted[stack->cnt - tmp / 3 * 2];
	pivot2 = stack->sorted[stack->cnt - tmp / 3];
	i = -1;
	while (++i < tmp && stack->ai >= tmp / 3)
	{
		int t = stack->a[stack->ai - 1];
		if (t < pivot2)
		{
			check_b(stack);
			do_order(stack, "pb");
			if (t < pivot1)
			{
				if (stack->a[stack->ai - 2] >= pivot2)
					do_order(stack, "rr");
				else
					do_order(stack, "rb");
			}
		}
		else
			do_order(stack, "ra");
	}
	i = -1;
	while (stack->b[stack->bi - 1] >= pivot1)
		do_order(stack, "rb");
	stack->div++;
}

void b_to_a(t_stack *stack)
{
	do_order(stack, "rrb");
	check_a(stack);
	do_order(stack, "pa");
}