/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:57:11 by naykim            #+#    #+#             */
/*   Updated: 2021/06/03 15:57:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->order = 0;
	stack->sum = 0;
}

void make_stack(t_stack *stack, int argc, char *argv[])
{
	int i;
	long long tmp;

	stack->cnt = argc;
	stack->a = (int *)malloc(sizeof(int) * argc);
	stack->b = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp == -1 || tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(stack, 1);
		stack->a[argc - i - 1] = tmp;
		i++;
	}
	stack->order = (char **)malloc(sizeof(char *) * 1);
	stack->order[0] = (char *)malloc(sizeof(char) * 4);
}

static int selec_sort(int *sorted, int argc)
{
	int i;
	int k;
	int min;
	int tmp;

	i = -1;
	while (i++ < argc / 2)
	{
		min = i;
		k = i + 1;
		while (k++ < argc)
		{
			if (sorted[min] > sorted[k])
				min = k;
		}
		tmp = sorted[min];
		sorted[min] = sorted[i];
		sorted[i] = tmp;
	}
	return (sorted[i - 1]);
}

void print(t_stack *stack)
{
	printf("\na: ");
	for (int i = 0; i < stack->cnt; i++)
		printf("%3d", stack->a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack->cnt; i++)
		printf("%3d", stack->b[i]);
	printf("\n");
}

void push_swap_special(t_stack *stack)
{
	if (stack->cnt == 2)
		push_swap_two(stack);
	else if (stack->cnt == 3)
		push_swap_three(stack);
	else if (stack->cnt == 5)
		push_swap_five(stack);
}

void push_swap(t_stack *stack)
{
	int *sorted;
	int ai;
	int bi;
	int pivot;

	ai = -1;
	sorted = (int *)malloc(sizeof(int) * stack->cnt);
	while (ai++ < stack->cnt)
		sorted[ai] = stack->a[ai];
	pivot = selec_sort(sorted, stack->cnt);
	ai = stack->cnt;
	bi = 0;
	//if (is_sorted())
	// while ? 
	// check if sorted
	// make order(with pivot)
}

int main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 1)
		ft_exit(&stack, 1);
	argc--;
	make_stack(&stack, argc, argv);
	print(&stack);
	printf("here1\n");
	if (argc == 2 || argc == 3 || argc == 5)
		push_swap_special(&stack);
	else
		push_swap(&stack);
	printf("\nfinal:");
	print(&stack);
	printf("\n");
	for (int i = 0; i < stack.sum; i++)
		printf("%s", stack.order[i]);
	printf("%d\n", stack.sum);
	return (ft_exit(&stack, 0));
}