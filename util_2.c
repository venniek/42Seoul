/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:50:23 by naykim            #+#    #+#             */
/*   Updated: 2021/06/10 12:50:24 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pow(int a, int b)
{
	int ans;

	ans = 1;
	while (b-- > 0)
		ans *= a;
	return (ans);
}

int is_ascending(t_stack *stack)
{
	int i;

	i = stack->cnt - 1;
	while (i > 0)
	{
		if (stack->a[i] > stack->a[i - 1])
			return (i);
		i--;
	}
	return (0);
}

void ft_free(char **str, int cnt)
{
	int i;

	i = -1;
	while (++i < cnt)
	{
		free(str[i]);
		str[i] = 0;
	}
	free(str);
	str = 0; 
}

int ft_exit(t_stack *stack, int i)
{
	if (stack->a != 0)
	{
		free(stack->a);
		stack->a = 0;
	}
	if (stack->b != 0)
	{
		free(stack->b);
		stack->b = 0;
	}
	if (stack->order != 0)
		ft_free(stack->order, stack->sum);
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void add_order(t_stack *stack, char *str)
{
	(stack->sum)++;
	ft_stradd(stack, str);
}

int selec_sort(int *sorted, t_stack *stack)
{
	int i;
	int k;
	int min;
	int tmp;

	i = -1;
	while (++i < stack->cnt - 1)
	{
		min = i;
		k = i;
		while (k++ < stack->cnt)
		{
			if (sorted[min] > sorted[k])
				min = k;
		}
		tmp = sorted[min];
		sorted[min] = sorted[i];
		sorted[i] = tmp;
		if (i > 0 && sorted[i] == sorted[i - 1])
		{
			free(sorted);
			sorted = 0;
			ft_exit(stack, 1);
		}
	}
	return (sorted[stack->cnt / 2]);
}
