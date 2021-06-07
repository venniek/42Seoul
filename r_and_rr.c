#include "push_swap.h"

void rotate_a(int *a, int *ai)
{
	int tmp;
	int i;

	tmp = a[*ai - 1];
	i = *ai;
	while (i-- >= 1)
		a[i] = a[i - 1];
	a[0] = tmp;
}

void rotate_b(int *b, int *bi)
{
	int tmp;
	int i;

	tmp = b[*bi - 1];
	i = *bi;
	while (i-- >= 1)
		b[i] = b[i - 1];
	b[0] = tmp;
}

void reverse_a(int *a, int *ai)
{
	int tmp;
	int i;

	tmp = a[0];
	i = -1;
	while (i++ < *ai - 1)
		a[i] = a[i + 1];
	a[*ai - 1] = tmp;
}

void reverse_b(int *b, int *bi)
{
	int tmp;
	int i;

	tmp = b[0];
	i = -1;
	while (i++ < *bi - 1)
		b[i] = b[i + 1];
	b[*bi - 1] = tmp;
}