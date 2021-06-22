/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:55:26 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:55:29 by naykim           ###   ########.fr       */
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

void	make_stack(t_stack *stack, int argc, char *argv[])
{
	int			i;
	long long	tmp;

	stack->cnt = argc;
	stack->a = (int *)malloc(sizeof(int) * argc);
	stack->b = (int *)malloc(sizeof(int) * argc);
	stack->sorted = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(stack, argv[i + 1]);
		if (tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(stack, 1);
		stack->a[argc - i - 1] = tmp;
		stack->sorted[argc - i - 1] = tmp;
		i++;
	}
	selec_sort(stack);
	make_div(stack);
	stack->ai = stack->cnt;
	stack->pivot = (int *)malloc(sizeof(int) * stack->div);
	stack->last = (char *)malloc(sizeof(char) * 4);
	stack->last = ft_strdup("");
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
}

int		main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 2)
		ft_exit(&stack, 0);
	argc--;
	make_stack(&stack, argc, argv);
	if (stack.cnt <= 5)
		push_swap_under5(&stack);
	else
		push_swap(&stack);
	ft_putstr_fd(stack.last, 1);
	return (ft_exit(&stack, 0));
}
