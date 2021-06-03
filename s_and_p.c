#include "push_swap.h"

void swap_a(int *a, int *ai)
{
	int tmp;

	if (*ai == 1 || *ai == 0)
		return ;
	tmp = a[*ai - 1];
	a[*ai - 1] = a[*ai - 2];
	a[*ai - 2] = tmp;
}

void swap_b(int *b, int *bi)
{
	int tmp;

	if (*bi == 1 || *bi == 0)
		return ;
	tmp = b[*bi - 1];
	b[*bi - 1] = b[*bi - 2];
	b[*bi - 2] = tmp;
}

void push_a(int *a, int *b, int *ai, int *bi)
{
	if (*bi == 0)
		return ;
	a[*ai] = b[*bi - 1];
	(*bi)--;
	(*ai)++;
}

void push_b(int *a, int *b, int *ai, int *bi)
{
	if (*ai == 0)
		return ;
	b[*bi] = a[*ai - 1];
	(*ai)--;
	(*bi)++;
}