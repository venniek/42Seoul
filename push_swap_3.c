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
	while (stack->ai > 5)
	{
		//if (stack->ai <= 100)
		//{
			if (stack->ai <= 30)
				stack->div = 2;
			else if (stack->ai <= 70)
				stack->div = 3;
			else if (stack->ai <= 100)
				stack->div = 3;
			else
			{
				while (stack->ai / stack->div >= 60)
					stack->div++;
			}
			a_to_b_under100(stack);
		//}
/*		else
		{
			if (stack->div <= 150)
				stack->div = 4;
			if (stack->ai <= 300)
				stack->div = 4;
			else
				stack->div = 5;
			a_to_b(stack);
			sort_b(stack);
		}
*/
	}
	push_swap_special(stack);
	while (stack->bi > 0)
	{
		b_to_a(stack);
		do_order(stack, "pa\n");
	}
}



void check_b(t_stack *stack)
{
	int btop;
	int atop;

	if (stack->bi == 0)
		return ;
	atop = stack->a[stack->ai - 1];
	btop = stack->b[stack->bi - 1];
	if (atop > btop)
		do_order(stack, "rb\n");
}

void sort_b(t_stack *stack)
{
	int i;

	i = 1;
	while (stack->b[stack->bi - i] != stack->sorted[stack->cnt - stack->ai - 1])
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

void sort_a(t_stack *stack)
{
	int i;

	i = 1;
	while (stack->a[stack->ai - i] != stack->sorted[0])
		i++;
	if (--i <= stack->ai / 2)
	{
		while (i-- > 0)
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
	int pivot1;
	int pivot2;
	int tmp;
	int i;
	int d;

	tmp = stack->ai;
	d = stack->div;
	pivot1 = stack->sorted[stack->cnt - tmp / d * (d - 1)];
	pivot2 = stack->sorted[stack->cnt - tmp / d * ft_max(1, (d - 2))];
	i = -1;
	while (i++ < tmp && stack->ai >= tmp / d * (d - 1))
	{
		if (stack->a[stack->ai - 1] < pivot1)
		{
			check_b(stack);
			do_order(stack, "pb\n");
		}
		else
			do_order(stack, "ra\n");
	}
}

void b_to_a(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->bi <= 1)
		return ;
	tmp = stack->sorted[stack->bi - 1];
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

}