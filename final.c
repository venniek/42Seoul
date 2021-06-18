#include "push_swap.h"


void default_stack(t_stack *stack)
{
	stack->cnt = 0;
	stack->a = 0;
	stack->b = 0;
	stack->sorted = 0;
	stack->ai = 0;
	stack->bi = 0;
	stack->div = 3;
	stack->sum = 0;
	stack->now = 0;
	stack->start = 0;
	stack->end = 0;
	stack->total = 0;
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
	if (stack->ai <= 30)
		stack->div = 2;
	stack->sum = stack->div;
	while (stack->now != stack->cnt)
	{
		a_to_b(stack);
		stack->start = stack->now;
		stack->end = stack->now + stack->bi - 1;
		while (stack->bi > 0)
		{	
			if (b_to_a(stack) == 1)
				do_order(stack, "pa\n");
			else
			{
				do_order(stack, "pa\n");
				do_order(stack, "ra\n");
			}
		}
		stack->div--;
		sort_a(stack);
	}
}

void sort_a(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->a[0] == stack->sorted[stack->now - 1])
		return ;
	while (stack->a[i] != stack->sorted[stack->now - 1])
		i++;
	if (i > stack->ai / 2)
	{
		while (++i <= stack->ai)
			do_order(stack, "ra\n");
	}
	else
	{
		while (i-- > 0)
			do_order(stack, "rra\n");
	}
}

void a_to_b(t_stack *stack)
{
	int pivot;
	int i;
	int d;
	int tmp;

	i = -1;
	d = stack->div;
	tmp = stack->ai;
	if (d == 1)
		pivot = stack->sorted[stack->cnt - 1] + 1;
	else
		pivot = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	while (++i < tmp && stack->bi < stack->cnt / stack->sum)
	{
		if (stack->now != 0 && stack->a[stack->ai - 1] == stack->sorted[0])
			break;
		if (stack->now == 0)
		{
			if (stack->a[stack->ai - 1] < pivot)
			{
				check_b(stack);
				do_order(stack, "pb\n");
			}
			else
				do_order(stack, "ra\n");
		}
		else
		{
			if (stack->a[stack->ai - 1] < pivot && stack->a[stack->ai - 1] > stack->sorted[stack->now - 1])
			{
				check_b(stack);
				do_order(stack, "pb\n");
			}
			else
				do_order(stack, "ra\n");
		}
	}
}

void check_b(t_stack *stack)
{
	int atop;
	int btop;

	if (stack->bi == 0)
		return ;
	atop = stack->a[stack->ai - 1];
	btop = stack->b[stack->bi - 1];
	if (atop < btop)
		do_order(stack, "rb\n");
}

int b_to_a(t_stack *stack)
{
	int big;
	int small;
	int bigi;
	int smalli;

	smalli = 0;
	bigi = 0;

	small = stack->sorted[stack->start];
	big = stack->sorted[stack->end];
	while (bigi < stack->bi - 1 && stack->b[bigi] != big)
		bigi++;
	while (smalli < stack->bi - 1 && stack->b[smalli] != small)
		smalli++;
	stack->now++;
	if (ft_abs(bigi - stack->bi / 2) >= ft_abs(smalli - stack->bi / 2))
	{
		rotate_b(stack, bigi);
		stack->end--;
		return (1); 
	}
	else
	{
		rotate_b(stack, smalli);
		stack->start++;
		return (2);
	}
}

void rotate_b(t_stack *stack, int i)
{
	if (i == stack->bi - 1)
		return ;
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
}