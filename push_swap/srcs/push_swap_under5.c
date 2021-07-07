/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:56:41 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:56:42 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap_under5(t_stack *stack)
{
	if (stack->ai == 2)
		push_swap_two(stack);
	else if (stack->ai == 3)
		push_swap_three(stack);
	else
		push_swap_f(stack);
}

void	push_swap_two(t_stack *stack)
{
	if (stack->a[stack->ai - 1] > stack->a[stack->ai - 2])
		do_order(stack, "sa");
}

void	push_swap_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
		return ;
	else if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
		do_order(stack, "sa");
	else if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0])
		do_order(stack, "rra");
	else if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1])
		do_order(stack, "ra");
	else if (stack->a[1] > stack->a[0] && stack->a[0] > stack->a[2])
	{
		do_order(stack, "sa");
		do_order(stack, "ra");
	}
	else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0])
	{
		do_order(stack, "sa");
		do_order(stack, "rra");
	}
}

void	push_swap_f(t_stack *stack)
{
	int	i;
	int	repeat;
	int	tmp;

	i = -1;
	repeat = stack->ai - 3;
	tmp = stack->cnt - stack->ai;
	while (++i < repeat)
		find_and_push(stack, i, tmp);
	push_swap_three(stack);
	i = -1;
	while (++i < repeat)
		do_order(stack, "pa");
}

void	find_and_push(t_stack *stack, int index, int tmp)
{
	int	i;

	i = stack->ai - 1;
	while (i > 0 && stack->a[i] != stack->sorted[tmp + index])
		i--;
	if (i >= stack->ai / 2)
	{
		while (++i < stack->ai)
			do_order(stack, "ra");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rra");
	}
	do_order(stack, "pb");
}
