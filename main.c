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
	stack->ai = stack->cnt;
	stack->order = (char **)malloc(sizeof(char *) * 1);
	stack->order[0] = (char *)malloc(sizeof(char) * 4);
}

void print(t_stack *stack)
{
	printf("\na: ");
	for (int i = 0; i < stack->ai; i++)
		printf("%3d", stack->a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack->bi; i++)
		printf("%3d", stack->b[i]);
	printf("\n");
}

void push_swap(t_stack *stack)
{
	int *sorted;
	int pivot;

	if (stack->cnt <= 5)
		push_swap_special(stack);
	sorted = (int *)malloc(sizeof(int) * stack->cnt);
	while (++ai < stack->cnt)
		sorted[ai] = stack->a[ai];
	pivot = selec_sort(sorted, stack->cnt);

}

int main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 2)
		ft_exit(&stack, 2);
	//same number error check?
	argc--;
	make_stack(&stack, argc, argv);
	print(&stack);
	push_swap(&stack);
	printf("\nfinal:");
	print(&stack);
	printf("\n");
	for (int i = 0; i < stack.sum; i++)
		printf("%s", stack.order[i]);
	printf("%d\n", stack.sum);
	return (ft_exit(&stack, 0));
}