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
	stack->now = 0;
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
	int pivot;
	int tmp;
	int i;

	i = -1;
	tmp = stack->cnt;
	if (tmp <= 5)
	{	
		push_swap_special(stack);
		return;
	}
	pivot = stack->sorted[tmp / 2];
	while (++i < tmp && stack->ai > tmp - (tmp + 1) / 2)
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
			do_order(stack, "pb\n");
	//		check_b(stack, pivot2);
		}
		else
			do_order(stack, "ra\n");
	}
//	printf("after first a_to_b\n");
//	print_stack(stack);
	while (stack->bi > 0)
		b_to_a(stack);
//	printf("after b_to_a\n");
//	print_stack(stack);
	i = -1;
	while (++i < tmp && stack->ai > tmp / 2)
	{
		if (stack->a[stack->ai - 1] >= pivot)
		{
			do_order(stack, "pb\n");
	//		check_b(stack, pivot2);
		}
		else
			do_order(stack, "ra\n");
	}
//	printf("after last a_to_b\n");
//	print_stack(stack);
	while (stack->bi > 0)
		b_to_a(stack);
	sort_a(stack);
}

void sort_a(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->a[i] != stack->sorted[stack->now - 1])
		i++;
	if (i >= stack->ai / 2)
	{
		while (++i <= stack->ai)
			do_order(stack, "ra\n");
	}
	else
	{
		while (i-- > 0)
			do_order(stack, "rra\n");
	}
}


void check_b(t_stack *stack, int pivot2)
{
	if (stack->bi <= 0)
		return ;
	if (stack->b[stack->bi - 1] > pivot2)
		do_order(stack, "rb\n");
}


void check_a(t_stack *stack)
{
	int tmp;
	int i;

	tmp = stack->b[stack->bi - 1];
	if (tmp > stack->a[0] && tmp < stack->a[stack->ai - 1])
		return ;
	i = 0;
	while (i < stack->ai - 1 && !(tmp < stack->a[i] && tmp > stack->a[i + 1]))
		i++;
	if (i == stack->ai - 1)
	{
		if (stack->now < stack->cnt / 2)
		{
			i = 0;
			while (i < stack->ai - 1 && !(stack->a[i] < stack->sorted[stack->cnt / 2] && stack->a[i] < stack->a[i + 1]))
				i++;
		}	
		else
		{
			i = 0;
			while (i < stack->ai - 1 && !(stack->a[i] < stack->a[i + 1]))
				i++;
		}
	}
	if (i >= stack->ai / 2)
	{
		while (++i < stack->ai)
			do_order(stack, "ra\n");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rra\n");
	}

}
/*
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
*/
/*
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
	while (stack->bi > 0)
		do_order(stack, "pa\n");
}
*/

void b_to_a(t_stack *stack)
{
	int *new_sort;
	int i;
	int pivot;
	int tmp;

	tmp = stack->bi;
	if (tmp <= 3)
	{
		push_swap_special_b(stack);
		return ;
	}
	new_sort = (int *)malloc(sizeof(int) * tmp);
	i = -1;
	while (++i < tmp)
		new_sort[i] = stack->b[i];
	sort_sort(new_sort, tmp);
	pivot = new_sort[(tmp + 1) / 2];
	i = -1;
	while (++i < tmp && stack->bi > tmp - (tmp + 1) / 2)
	{
		if (stack->b[stack->bi - 1] < pivot)
		{
			check_a(stack);
			do_order(stack, "pa\n");
			stack->now++;
		}
		else
			do_order(stack, "rb\n");
	}
}
