/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:56:33 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:56:35 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, char c)
{
	int tmp;

	if (c == 'a')
	{
		if (stack->ai == 1 || stack->ai == 0)
			return ;
		tmp = stack->a[stack->ai - 1];
		stack->a[stack->ai - 1] = stack->a[stack->ai - 2];
		stack->a[stack->ai - 2] = tmp;
	}
	else if (c == 'b')
	{
		if (stack->bi == 1 || stack->bi == 0)
			return ;
		tmp = stack->b[stack->bi - 1];
		stack->b[stack->bi - 1] = stack->b[stack->bi - 2];
		stack->b[stack->bi - 2] = tmp;
	}
}

void	push(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (stack->bi == 0)
			return ;
		stack->a[stack->ai] = stack->b[stack->bi - 1];
		(stack->bi)--;
		(stack->ai)++;
	}
	else if (c == 'b')
	{
		if (stack->ai == 0)
			return ;
		stack->b[stack->bi] = stack->a[stack->ai - 1];
		(stack->ai)--;
		(stack->bi)++;
	}
}

void	rotate(t_stack *stack, char c)
{
	int tmp;
	int i;

	if (c == 'a')
	{
		tmp = stack->a[stack->ai - 1];
		i = stack->ai;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = tmp;
	}
	else if (c == 'b')
	{
		tmp = stack->b[stack->bi - 1];
		i = stack->bi;
		while (--i >= 1)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = tmp;
	}
}

void	reverse(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	if (c == 'a')
	{
		tmp = stack->a[0];
		i = -1;
		while (i++ < stack->ai - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->ai - 1] = tmp;
	}
	else if (c == 'b')
	{
		tmp = stack->b[0];
		i = -1;
		while (i++ < stack->bi - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->bi - 1] = tmp;
	}
}

void	do_order(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0)
		push(stack, str[1]);
	else if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0)
		swap(stack, str[1]);
	else if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0)
		rotate(stack, str[1]);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0)
		reverse(stack, str[2]);
	if (merge_order(stack, str))
	{
		ft_strfree(stack->last);
		if (str[0] == 's')
			stack->last = ft_strdup("ss\n");
		else if (str[0] == 'r' && str[1] != 'r')
			stack->last = ft_strdup("rr\n");
		else if (str[1] == 'r')
			stack->last = ft_strdup("rrr\n");
	}
	else
	{
		ft_putstr_fd(stack->last, 1);
		ft_strfree(stack->last);
		stack->last = ft_strdup(str);
	}
}
