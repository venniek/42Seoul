#include "push_swap.h"

/*
void a_to_b_under100(t_stack *stack)
{
	int pivot1;
	int tmp;
	int i;
	int d;

	tmp = stack->ai;
	d = stack->div;
	pivot1 = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	i = -1;
	while (i++ < tmp && stack->ai >= tmp / d * (d - 1))
	{
		if (stack->a[stack->ai - 1] < pivot1)
		{
			check_b_under100(stack);
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
}*/
void a_to_b_under100(t_stack *stack)
{
	int pivot;
	int first;
	int last;
	int tmp;
	int d;
	int i;

	i = -1;
	tmp = stack->ai;
	d = stack->div;
	pivot = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	while (++i < tmp && stack->ai >= tmp / d * (d - 1))
	{
		first = stack->ai - 1;
		last = 0;
		while (stack->a[first] > pivot)
			first--;
		while (stack->a[last] > pivot)
			last++;
		if (stack->ai - 1 - first <= last + 1)
		{
			while (++first < stack-> ai)
				do_order(stack, "ra\n");
		}
		else
		{
			while (last-- >= 0)
				do_order(stack, "rra\n");
		}
		check_b_under100(stack);
		do_order(stack, "pb\n");
	}
}
void check_b_under100(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->bi <= 1)
		return ;
	tmp = stack->a[stack->ai - 1];
	i = stack->bi - 1;
	if (tmp < stack->b[0] && tmp > stack->b[i])
		return ;
	while (i > 0 && !(tmp < stack->b[i] && tmp > stack->b[i - 1]))
		i--;
	if (i == 0)
	{
		while (i++ < stack->bi && stack->b[stack->bi - i] > stack->b[stack->bi - i - 1])
			;
		if (i == stack->bi)
			return ;
		if (--i < stack->bi / 2)
		{
			while (i-- >= 0)
				do_order(stack, "rb\n");
		}
		else
		{
			while (++i < stack->bi)
				do_order(stack, "rrb\n");
		}	
	}
	else if (--i >= stack->bi / 2)
	{
		while (++i < stack->bi)
			do_order(stack, "rb\n");
	}
	else
	{
		while (i-- >= 0)
			do_order(stack, "rrb\n");
	}
}

void b_to_a_under100(t_stack *stack)
{
	int i;

	i = stack->bi - 1;
	while (stack->b[i] != stack->sorted[stack->cnt - stack->ai - 1])
			i--;
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
	while (stack->bi > 0)
		do_order(stack, "pa\n");
}