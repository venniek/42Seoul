#include "push_swap.h"	
	
void push_swap_two(t_stack *stack)
{
	stack->ai = 2;
	if (stack->a[0] < stack->a[1])
		swap_a(stack);
}

void push_swap_three(t_stack *stack)
{
	stack->ai = 3;
	if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])      // 3, 1, 2
		swap_a(stack);
	else if (stack->a[1] > stack->a[0] && stack->a[0] > stack->a[2]) // 2, 3, 1
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0]) // 1, 3, 2
		reverse_a(stack);
	else if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1]) // 2, 1, 3
		rotate_a(stack);
	else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0]) // 1, 2, 3
	{
		swap_a(stack);
		reverse_a(stack);
	}
}

void push_swap_five(t_stack *stack)
{
	int i;

	stack->ai = 5;
	stack->bi = 0;
	i = -1;
	while (++i < 2)
	{
		if (stack->a[stack->ai - 1] > stack->a[stack->ai - 2])
			swap_a(stack);
		printf("repeat %d\n", i);
		push_b(stack);
	}
	push_swap_three(stack);
	i = -1;
	while (++i < 2)
	{
		while (stack->a[stack->ai - 1] < stack->b[stack->bi - 1])
			rotate_a(stack);
		push_a(stack);
	}
	while (stack->a[stack->ai - 1] < stack->a[stack->ai - 2])
		rotate_a(stack);
	rotate_a(stack);
}