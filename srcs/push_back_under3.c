/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_under3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:56:50 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:56:53 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back_two(t_stack *stack)
{
	if (stack->b[stack->bi - 1] < stack->b[stack->bi - 2])
		do_order(stack, "sb");
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
		do_order(stack, "rrb");
	else if (stack->b[1] > stack->b[0] && stack->b[0] > stack->b[2])
		do_order(stack, "rb");
	else if (stack->b[1] > stack->b[2] && stack->b[2] > stack->b[0])
		do_order(stack, "sb");
	else if (stack->b[2] > stack->b[0] && stack->b[0] > stack->b[1])
	{
		do_order(stack, "sb");
		do_order(stack, "rb");
	}
	else if (stack->b[2] < stack->b[1] && stack->b[1] < stack->b[0])
	{
		do_order(stack, "sb");
		do_order(stack, "rrb");
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
		do_order(stack, "pa");
		stack->now++;
	}
}
