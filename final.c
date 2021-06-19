#include "push_swap.h"


void default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->sorted = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->start = 0;
	stack->end = 0;
}

void make_stack(t_stack *stack, int argc, char *argv[])
{
	int i;
	long long tmp;

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
	stack->ai = stack->cnt;
}

void push_swap(t_stack *stack)
{
	int i;

	i = -1;
	while (stack->ai > 5)
		a_to_b(stack);
	push_swap_special(stack);
	stack->end = stack->bi - 1;
	stack->start = 0;
	while (stack->bi > 0)
	{
		if (b_to_a(stack) == 1)
		{
			do_order(stack, "pa\n");
			stack->end--;
		}
		else
		{
			do_order(stack, "pa\n");
			do_order(stack, "ra\n");
			stack->start++;
		}
	}
	sort_b(stack);
}

void a_to_b(t_stack *stack)
{
	int pivot;
	int i;
	int tmp;

	tmp = stack->ai;
	pivot = stack->sorted[stack->cnt - (tmp + 1) / 2];
	i = -1;
	while (++i < tmp && stack->ai > tmp / 2)
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
			check_b(stack);
			do_order(stack, "pb\n");
		}
		else
		{
			do_order(stack, "ra\n");
		}
	}
}

void check_b(t_stack *stack)
{
	if (stack->bi <= 1)
		return ;
	if (stack->a[stack->ai - 1] < stack->b[stack->bi - 1])
		do_order(stack, "rb\n");
}

int b_to_a(t_stack *stack)
{
	int big;
	int small;
	int i;

	big = stack->sorted[stack->end];
	small = stack->sorted[stack->start];
	i = 0;
	while (!(stack->b[i] == big || stack->b[i] == small))
		i++;
	if (i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			do_order(stack, "rb\n");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rrb\n");
	}
	if (stack->b[stack->bi - 1] == big)
		return (1);
	else if (stack->b[stack->bi - 1] == small)
		return (2);
	return (0);
}

void sort_b(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->a[i] != stack->sorted[0])
		i++;
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