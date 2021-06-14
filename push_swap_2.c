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
	stack->div = 2;
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
	while (stack->ai / stack->div > 5)
		stack->div++;
	while (stack->ai > 5)
	{
		a_to_b(stack);
	}
	push_swap_special(stack);
	b_to_a(stack);
}


///new
/*
void a_to_b(t_stack *stack)
{
	int pivot;
	int first;
	int last;
	int tmp;
	int d;
	int i;

	i = -1;
	d = stack->cnt / stack->div;
	tmp = stack->ai;
	pivot = stack->sorted[stack->cnt + d - tmp];
	while (++i < tmp && stack->ai >= tmp - d)
	{
		first = stack->ai - 1;
		last = 0;
		while (stack->a[first] > pivot)
			first--;
		while (stack->a[last] > pivot)
			last++;
		if (stack->ai - 1 - first <= last + 1)
		{
			while (++first < stack-> ai)
				do_order(stack, "ra\n");
		}
		else
		{
			while (last-- >= 0)
				do_order(stack, "rra\n");
		}
		check_b(stack);
		do_order(stack, "pb\n");
	}
	printf("\n");
	for (int i = 0; i < stack->bi; i++)
		printf("%3d ", stack->b[i]);
	printf("\n");
}
*/


//original
void a_to_b(t_stack *stack)
{
	int pivot;
	int tmp;
	int i;
	int d;

	tmp = stack->ai;
	d = stack->div;
	pivot = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	i = -1;
	while (i++ < tmp && stack->ai >= tmp / d * (d - 1))
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
			check_b(stack);
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
}


/*
//only test
void a_to_b(t_stack *stack)
{
	int i = -1;
	int tmp = stack->ai;

	while (i++ < tmp)
	{
		check_b(stack);
		do_order(stack, "pb\n");
	}
}
*/
void b_to_a(t_stack *stack)
{
	int i;

	i = stack->bi - 1;
	while (stack->b[i] != stack->sorted[stack->cnt - stack->ai - 1])
			i--;
	if (i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			do_order(stack, "rb\n");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rrb\n");
	}
	i = stack->bi;
	while (stack->bi > 0)
		do_order(stack, "pa\n");
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
				do_order(stack, "rb\n");
		}
		else
		{
			while (++i < stack->bi)
				do_order(stack, "rrb\n");
		}	
	}
	else if (--i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			do_order(stack, "rb\n");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rrb\n");
	}
}