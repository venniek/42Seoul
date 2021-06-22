/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_under3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:50:54 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 17:40:41 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back_two(t_stack *stack)
{
	if (stack->b[stack->bi - 1] < stack->b[stack->bi - 2])
		do_order(stack, "sb\n");
	push_back_to_a(stack, 2);
}

void	push_back_three(t_stack *stack)
{
	if (stack->bi <= 2)
	{
		push_back_two(stack);
		return ;
	}
	if (stack->b[0] < stack->b[1] && stack->b[1] < stack->b[2])
		;
	else if (stack->b[0] > stack->b[2] && stack->b[2] > stack->b[1])
		do_order(stack, "rrb\n");
	else if (stack->b[1] > stack->b[0] && stack->b[0] > stack->b[2])
		do_order(stack, "rb\n");
	else if (stack->b[1] > stack->b[2] && stack->b[2] > stack->b[0])
		do_order(stack, "sb\n");
	else if (stack->b[2] > stack->b[0] && stack->b[0] > stack->b[1])
	{
		do_order(stack, "sb\n");
		do_order(stack, "rb\n");
	}
	else if (stack->b[2] < stack->b[1] && stack->b[1] < stack->b[0])
	{
		do_order(stack, "sb\n");
		do_order(stack, "rrb\n");
	}
	push_back_to_a(stack, 3);
}

void	push_back_to_a(t_stack *stack, int a)
{
	int	i;

	i = -1;
	while (++i < a)
	{
		check_a(stack);
		do_order(stack, "pa\n");
		stack->now++;
	}
}
