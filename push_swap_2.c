#include "push_swap.h"


void default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->sorted = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->div = 2;
	stack->sum = 0;
	stack->now = 0;
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
	while (stack->ai > 2)
	{
		if (stack->ai <= 30)
			stack->div = 2;
		else
			stack->div = 3;
		if (stack->div >= 4)
			a_to_b_find(stack);
		else
			a_to_b_under100(stack);
		
	}
	push_swap_special(stack);
	while (stack->bi > 0)
	{
		b_to_a(stack);
	}
}

void a_to_b_under100(t_stack *stack)
{
	int pivot;
	int tmp;
	int i;
	int d;

	tmp = stack->ai;
	d = stack->div;
	pivot = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	i = -1;
	while (i++ < tmp && stack->ai > stack->now)
	{
		if (stack->a[stack->ai - 1] < pivot)
		{
			check_b(stack);
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
	sort_b(stack, i + 1);
}

void a_to_b_find(t_stack *stack)
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
	while (++i < tmp && stack->ai >= stack->now)
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
		check_b(stack);
		do_order(stack, "pb\n");
	}
//	sort_b(stack, i + 1);
}

void check_b(t_stack *stack)
{
	int btop;
	int atop;

	if (stack->bi <= 1)
		return ;
	atop = stack->a[stack->ai - 1];
	btop = stack->b[stack->bi - 1];
	if (atop < btop)
		do_order(stack, "rb\n");
}

void sort_b(t_stack *stack, int num)
{
	int i;
	int tmp;

	if (stack->bi <= 1)
		return ;
	tmp = stack->sorted[stack->bi - num];
	if (tmp == 0)
		tmp = stack->sorted[stack->bi - 1] + 1;
	i = stack->bi - 1;
	if (tmp > stack->b[0] && tmp < stack->b[i])
		return ;
	while (i > 0 && !(tmp > stack->b[i] && tmp < stack->b[i - 1]))
		i--;
	if (i == 0)
	{
		while (i++ < stack->bi && stack->b[stack->bi - i] < stack->b[stack->bi - i - 1])
			;
		if (i == stack->bi)
			return ;
		if (--i < stack->bi / 2)
		{
			while (i-- > 0)
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
		while (i-- > 0)
			do_order(stack, "rrb\n");
	}
}
/*
void sort_b(t_stack *stack)
{
	int i;

	i = 1;
	while (stack->b[stack->bi - i] != stack->sorted[stack->bi - 1])
		i++;
	if (--i <= stack->bi / 2)
	{
		while (i-- > 0)
			do_order(stack, "rb\n");
	}
	else
	{
		while (i-- > 0)
			do_order(stack, "rrb\n");
	}
}
*/
void b_to_a(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->bi <= 1)
		return ;
	tmp = stack->sorted[stack->now++];
	i = stack->bi - 1;
	while (i > 0 && stack->b[i] != tmp)
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
	do_order(stack, "pa\n");
	do_order(stack, "ra\n");
}