#include "push_swap.h"

void swap_a(t_stack *stack)
{
	int tmp;

	add_order(stack, "sa\n");
	if (stack->ai == 1 || stack->ai == 0)
		return ;
	tmp = stack->a[stack->ai - 1];
	stack->a[stack->ai - 1] = stack->a[stack->ai - 2];
	stack->a[stack->ai - 2] = tmp;
}

void swap_b(t_stack *stack)
{
	int tmp;

	add_order(stack, "sb\n");
	if (stack->bi == 1 || stack->bi == 0)
		return ;
	tmp = stack->b[stack->bi - 1];
	stack->b[stack->bi - 1] = stack->b[stack->bi - 2];
	stack->b[stack->bi - 2] = tmp;
}

void push_a(t_stack *stack)
{
	add_order(stack, "pa\n");
	if (stack->bi == 0)
		return ;
	stack->a[stack->ai] = stack->b[stack->bi - 1];
	(stack->bi)--;
	(stack->ai)++;
}

void push_b(t_stack *stack)
{
	add_order(stack, "pb\n");
	if (stack->ai == 0)
		return ;
	stack->b[stack->bi] = stack->a[stack->ai - 1];
	(stack->ai)--;
	(stack->bi)++;
}