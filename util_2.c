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

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

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
	if (stack->sorted != 0)
	{
		free(stack->sorted);
		stack->sorted = 0;
	}
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void print_order(t_stack *stack, char *str)
{
	ft_putstr_fd(str, 1);
	printf("\na: ");
	for (int i = 0; i < stack->ai; i++)
		printf("%3d ", stack->a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack->bi; i++)
		printf("%3d ", stack->b[i]);
	printf("\n");
	stack->total++;
}

int selec_sort(t_stack *stack)
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
		while (++k < stack->cnt)
		{
			if (stack->sorted[min] > stack->sorted[k])
				min = k;
		}
		tmp = stack->sorted[min];
		stack->sorted[min] = stack->sorted[i];
		stack->sorted[i] = tmp;
		if (i > 0 && stack->sorted[i] == stack->sorted[i - 1])
		{
			free(stack->sorted);
			stack->sorted = 0;
			ft_exit(stack, 1);
		}
	}
	return (stack->sorted[stack->cnt / 2]);
}

void sort_sort(int *sort, int len)
{
	int i;
	int k;
	int min;
	int tmp;

	i = -1;
	while (++i < len - 1)
	{
		min = i;
		k = i;
		while (++k < len)
		{
			if (sort[min] > sort[k])
				min = k;
		}
		tmp = sort[min];
		sort[min] = sort[i];
		sort[i] = tmp;
	}
}