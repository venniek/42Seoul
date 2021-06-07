#include "push_swap.h"	
	
void push_swap_two(int *a)
{
	int ai;

	ai = 2;
	if (a[0] < a[1])
		swap_a(a, &ai);
}

void push_swap_three(int *a)
{
	int ai;

	ai = 3;
	if (a[0] > a[2] && a[2] > a[1])      // 3, 1, 2
		swap_a(a, &ai);
	else if (a[1] > a[0] && a[0] > a[2]) // 2, 3, 1
	{
		swap_a(a, &ai);
		rotate_a(a, &ai);
	}
	else if (a[1] > a[2] && a[2] > a[0]) // 1, 3, 2
		reverse_a(a, &ai);
	else if (a[2] > a[0] && a[0] > a[1]) // 2, 1, 3
		rotate_a(a, &ai);
	else if (a[2] > a[1] && a[2] > a[0]) // 1, 2, 3
	{
		swap_a(a, &ai);
		reverse_a(a, &ai);
	}
}

void push_swap_five(int *a, int *b)
{
	int ai;
	int bi;
	int i;

	ai = 5;
	bi = 0;
	i = 0;
	while (i++ < 2)
	{
		if (a[ai - 1] > a[ai - 2])
			swap_a(a, &ai);
		push_b(a, b, &ai, &bi);
	}
		print(a, b, 5);

	push_swap_three(a);
	print(a, b, 5);
	i = 0;
	while (i++ < 2)
	{
		while (a[ai - 1] < b[bi - 1])
			rotate_a(a, &ai);
		push_a(a, b, &ai, &bi);
			print(a, b, 5);
	}
	while (a[ai - 1] < a[ai - 2])
		rotate_a(a, &ai);
	rotate_a(a, &ai);
}