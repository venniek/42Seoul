/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:55:26 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 20:12:20 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	default_stack(t_stack *stack)
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

void add_one_a(t_stack *stack)
{
	int i;
	int *newa;

	newa = (int *)malloc(sizeof(int) * (stack->ai + 1));
	i = -1;
	while (++i < stack->ai)
		newa[i] = stack->a[i];
	ft_intfree(stack->a);
	stack->a = newa;
}

void swap_stack(int *a, int len)
{
	int i = -1;
	int tmp;

	while (++i < len / 2)
	{
		tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp;
	}
}

void	make_stack(t_stack *stack, int argc, char *argv[])
{
	int			i;
	long long	tmp;
	int k;

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
	swap_stack(stack->a, stack->ai);
	stack->cnt = stack->ai;
	if (stack->cnt <= 1)
		return ;
	stack->b = (int *)malloc(sizeof(int) * stack->cnt);
	stack->sorted = (int *)malloc(sizeof(int) * stack->cnt);
	i = -1;
	while (++i < stack->cnt)
		stack->sorted[i] = stack->a[i];
	selec_sort(stack);
	make_div(stack);
	stack->pivot = (int *)malloc(sizeof(int) * stack->div);
}

long long	ft_atoi(t_stack *stack, const char *str, int *k)
{
	long long	atoi;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (ft_strchr("\t\n\v\f\r ", str[i]))
	{
		(*k)++;	
		i++;
	}
	if (str[i] == '-')
	{
		(*k)++;
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			atoi = atoi * 10 + str[i] - '0';
			(*k)++;
		}
		else if (ft_strchr("\t\n\v\f\r ", str[i]))
			break ;
		else
			ft_exit(stack, 1);
		i++;
	}
	return (sign * atoi);
}

void	make_div(t_stack *stack)
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

void	selec_sort(t_stack *stack)
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
			ft_exit(stack, 1);
	}
	if (stack->sorted[stack->cnt - 1] == stack->sorted[stack->cnt - 2])
		ft_exit(stack, 1);
}

int		main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 1)
		ft_exit(&stack, 0);
	make_stack(&stack, argc, argv);
	if (stack.cnt == 1)
		ft_exit(&stack, 0);
	if (check_sort(&stack) == 0)
		ft_exit(&stack, 0);
	if (stack.cnt <= 5)
		push_swap_under5(&stack);
	else
		push_swap(&stack);
	print_order(&stack);
	ft_exit(&stack, 0);
}
