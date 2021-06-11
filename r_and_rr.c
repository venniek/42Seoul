/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_and_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:49:55 by naykim            #+#    #+#             */
/*   Updated: 2021/06/10 12:49:57 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stack *stack)
{
	int tmp;
	int i;

	add_order(stack, "ra\n");
	tmp = stack->a[stack->ai - 1];
	i = stack->ai;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = tmp;
}

void rotate_b(t_stack *stack)
{
	int tmp;
	int i;

	add_order(stack, "rb\n");
	tmp = stack->b[stack->bi - 1];
	i = stack->bi;
	while (--i >= 1)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = tmp;
}

void reverse_a(t_stack *stack)
{
	int tmp;
	int i;

	add_order(stack, "rra\n");
	tmp = stack->a[0];
	i = -1;
	while (i++ < stack->ai - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->ai - 1] = tmp;
}

void reverse_b(t_stack *stack)
{
	int tmp;
	int i;

	add_order(stack, "rrb\n");
	tmp = stack->b[0];
	i = -1;
	while (i++ < stack->bi - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->bi - 1] = tmp;
}
