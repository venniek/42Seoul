/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:58 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 18:20:40 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_pivot(t_stack *stack)
{
	int	*new_sort;
	int	i;
	int	tmp;

	tmp = stack->bi;
	new_sort = (int *)malloc(sizeof(int) * tmp);
	i = -1;
	while (++i < tmp)
		new_sort[i] = stack->b[i];
	sort_sort(new_sort, tmp);
	tmp = new_sort[(tmp + 1) / 2];
	free(new_sort);
	new_sort = 0;
	return (tmp);
}

void	sort_a(t_stack *stack)
{
	int	i;

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

void	check_a(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->b[stack->bi - 1];
	if (tmp > stack->a[0] && tmp < stack->a[stack->ai - 1])
		return ;
	i = 0;
	while (i < stack->ai - 1 && !(tmp < stack->a[i] && tmp > stack->a[i + 1]))
		i++;
	if (i == stack->ai - 1)
	{
		i = 0;
		while (i < stack->ai - 1 && !(stack->a[i] < stack->a[i + 1]))
			i++;
	}
	rotate_a(stack, i);
}

void	check_a_first(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->b[stack->bi - 1];
	if (tmp > stack->a[0] && tmp < stack->a[stack->ai - 1])
		return ;
	i = 0;
	while (i < stack->ai - 1 && !(tmp < stack->a[i] && tmp > stack->a[i + 1]))
		i++;
	if (i == stack->ai - 1)
	{
		i = 0;
		while (i < stack->ai - 1)
		{
			if (stack->a[i] < stack->pivot[0] && stack->a[i] < stack->a[i + 1])
				break ;
			i++;
		}
	}
	rotate_a(stack, i);
}

void	rotate_a(t_stack *stack, int i)
{
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
