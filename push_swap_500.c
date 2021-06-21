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

void push_swap_500(t_stack *stack)
{
	int pivot1;
	int pivot2;
	int tmp;
	int i;


	i = -1;
	tmp = stack->cnt;
	pivot1 = stack->sorted[tmp / 3];
	pivot2 = stack->sorted[tmp / 3 * 2];
	while (++i < tmp && stack->bi < tmp / 3)
	{
		if (stack->a[stack->ai - 1] < pivot1)
		{
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
	while (stack->bi > 0)
		b_to_a_500(stack);
	sort_a(stack);
//	print_stack(stack);
	i = -1;
	while (++i < tmp && stack->bi < tmp / 3 * 2 - tmp / 3)
	{
		if (stack->a[stack->ai - 1] >= pivot1 && stack->a[stack->ai - 1] < pivot2)
		{
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
	while (stack->bi > 0)
		b_to_a_500(stack);
	sort_a(stack);
//	print_stack(stack);
	i = -1;
	while (++i < tmp && stack->bi < tmp - tmp / 3 * 2)
	{
		if (stack->a[stack->ai - 1] >= pivot2)
			do_order(stack, "pb\n");
		else
			do_order(stack, "ra\n");
	}
	while (stack->bi > 0)
		b_to_a_500(stack);
	sort_a(stack);
//	print_stack(stack);
}


void check_a_500(t_stack *stack)
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
		if (stack->now < stack->cnt / 3)
		{
			i = 0;
			while (i < stack->ai - 1 && !(stack->a[i] < stack->sorted[stack->cnt / 3] && stack->a[i] < stack->a[i + 1]))
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

void b_to_a_500(t_stack *stack)
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
			check_a_500(stack);
			do_order(stack, "pa\n");
			stack->now++;
		}
		else
			do_order(stack, "rb\n");
	}
}
