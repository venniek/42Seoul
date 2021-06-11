/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:50:54 by naykim            #+#    #+#             */
/*   Updated: 2021/06/10 12:50:58 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void push_swap_special(t_stack *stack)
{
	if (stack->cnt == 2)
		push_swap_two(stack);
	else if (stack->cnt == 3)
		push_swap_three(stack);
	else
		push_swap_f(stack);
}

void push_swap_two(t_stack *stack)
{
	stack->ai = 2;
	if (stack->a[0] < stack->a[1])
		swap_a(stack);
}

void push_swap_three(t_stack *stack)
{
	stack->ai = 3;
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
		return ;
	else if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1]) // 3, 1, 2
		swap_a(stack);
	else if (stack->a[1] > stack->a[0] && stack->a[0] > stack->a[2]) // 2, 3, 1
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0]) // 1, 3, 2
		reverse_a(stack);
	else if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1]) // 2, 1, 3
		rotate_a(stack);
	else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0]) // 1, 2, 3
	{
		swap_a(stack);
		reverse_a(stack);
	}
	else
		ft_exit(stack, 1);
}

void push_swap_f(t_stack *stack)
{
	int i;
	int *sorted;

	sorted = (int *)malloc(sizeof(int) * stack->cnt);
	i = -1;
	while (++i < stack->ai)
		sorted[i] = stack->a[i];
	selec_sort(sorted, stack);
	i = -1;
	while (++i < stack->cnt - 3)
		find_and_push(stack, sorted, i);
	push_swap_three(stack);
	i = -1;
	while (++i < stack->cnt - 3)
		push_a(stack);
	free(sorted);
	sorted = 0;
}

void find_and_push(t_stack *stack, int *sorted, int index)
{
	int i;

	i = stack->ai - 1;
	while (stack->a[i] != sorted[index])
		i--;
	if (i >= stack->ai / 2)
	{
		while (++i < stack->ai)
			rotate_a(stack);
		push_b(stack);
	}
	else
	{
		while (i-- >= 0)
			reverse_a(stack);
		push_b(stack);
	}
}
