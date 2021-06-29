/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:55:26 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:42:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->sorted = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->now = 0;
	stack->div = 0;
	stack->pivot = 0;
	stack->last = 0;
}

void			make_stack(t_stack *stack, int argc, char *argv[])
{
	int			i;
	long long	tmp;
	int			k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
		{
			tmp = ft_atoi(stack, &argv[i][k], &k);
			if (tmp >= 2147483648 || tmp < -2147483648)
				ft_exit(stack, 1);
			add_one_a(stack);
			stack->a[stack->ai++] = tmp;
		}
		i++;
	}
	stack->cnt = stack->ai;
	if (stack->cnt <= 1)
		return ;
	swap_stack(stack->a, stack->ai);
	malloc_all(stack);
}

void			make_div(t_stack *stack)
{
	if (stack->cnt <= 80)
		stack->div = 2;
	else if (stack->cnt <= 100)
		stack->div = 3;
	else if (stack->cnt <= 300)
		stack->div = 5;
	else if (stack->cnt <= 500)
		stack->div = 6;
	else
		stack->div = 7;
}

void			selec_sort(t_stack *stack)
{
	int			i;
	int			k;
	int			min;
	int			tmp;

	i = -1;
	while (++i < stack->cnt - 1)
	{
		min = i;
		k = i;
		while (++k < stack->cnt)
		{
			if (stack->sorted[min] > stack->sorted[k])
				min = k;
		}
		tmp = stack->sorted[min];
		stack->sorted[min] = stack->sorted[i];
		stack->sorted[i] = tmp;
		if (i > 0 && stack->sorted[i] == stack->sorted[i - 1])
			ft_exit(stack, 1);
	}
	if (stack->sorted[stack->cnt - 1] == stack->sorted[stack->cnt - 2])
		ft_exit(stack, 1);
}
