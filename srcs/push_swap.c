/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:57:11 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 18:19:45 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *stack)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = stack->cnt;
	while (++i < stack->div - 1)
		stack->pivot[i] = stack->sorted[tmp / stack->div * (i + 1)];
	stack->pivot[i] = stack->sorted[tmp - 1] + 1;
	push_swap_first(stack);
	a_to_b(stack);
	sort_a(stack);
}

void	push_swap_first(t_stack *stack)
{
	int	i;
	int	tmp;

	tmp = stack->cnt;
	i = -1;
	while (++i < tmp && stack->bi < tmp / stack->div)
	{
		if (stack->a[stack->ai - 1] < stack->pivot[0])
			do_order(stack, "pb\n");
		else
			do_order(stack, "ra\n");
	}
	while (stack->bi > 0)
		b_to_a_first(stack);
}

void	b_to_a_first(t_stack *stack)
{
	int	i;
	int	pivot;
	int	tmp;

	tmp = stack->bi;
	if (tmp <= 3)
	{
		push_back_three(stack);
		return ;
	}
	pivot = find_pivot(stack);
	i = -1;
	while (++i < tmp && stack->bi > tmp - tmp / 3)
	{
		if (stack->b[stack->bi - 1] < pivot)
		{
			check_a_first(stack);
			do_order(stack, "pa\n");
			stack->now++;
		}
		else
			do_order(stack, "rb\n");
	}
}

void	a_to_b(t_stack *stack)
{
	int	pi;
	int	i;
	int	tmp;
	int atop;

	tmp = stack->cnt;
	pi = 0;
	while (++pi < stack->div)
	{
		i = -1;
		while (++i < tmp)
		{
			if (pi != stack->div - 1 && stack->ai <= tmp - tmp / stack->div)
				break ;
			if (pi == stack->div - 1 && stack->ai == stack->now)
				break ;
			atop = stack->a[stack->ai - 1];
			if (atop >= stack->pivot[pi - 1] && atop < stack->pivot[pi])
				do_order(stack, "pb\n");
			else
				do_order(stack, "ra\n");
		}
		while (stack->bi > 0)
			b_to_a(stack);
	}
}

void	b_to_a(t_stack *stack)
{
	int	i;
	int	pivot;
	int	tmp;

	tmp = stack->bi;
	if (tmp <= 3)
	{
		push_back_three(stack);
		return ;
	}
	pivot = find_pivot(stack);
	i = -1;
	while (++i < tmp && stack->bi > tmp - tmp / 3)
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