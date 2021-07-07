/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:54:29 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:54:45 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->a[i] != stack->sorted[0])
		i++;
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
			do_order(stack, "ra");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rra");
	}
}

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
	tmp = new_sort[tmp / 3];
	free(new_sort);
	new_sort = 0;
	return (tmp);
}
