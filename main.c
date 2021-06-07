/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:57:11 by naykim            #+#    #+#             */
/*   Updated: 2021/06/03 15:57:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static int selec_sort(int *sorted, int argc)
{
	int i;
	int k;
	int min;
	int tmp;

	i = -1;
	while (i++ < argc / 2)
	{
		min = i;
		k = i + 1;
		while (k++ < argc)
		{
			if (sorted[min] > sorted[k])
				min = k;
		}
		tmp = sorted[min];
		sorted[min] = sorted[i];
		sorted[i] = tmp;
	}
	return (sorted[i - 1]);
}

void print(int *a, int *b, int argc)
{
	printf("\na: ");
	for (int i = 0; i < argc; i++)
		printf("%3d", a[i]);
	printf("\nb: ");
	for (int i = 0; i < argc; i++)
		printf("%3d", b[i]);
	printf("\n");
}

void push_swap_special(int *a, int *b, int argc)
{
	if (argc == 2)
		push_swap_two(a);
	else if (argc == 3)
		push_swap_three(a);
	else if (argc == 5)
		push_swap_five(a, b);
}

void push_swap(int *a, int *b, int argc)
{
	int *sorted;
	int ai;
	int bi;
	int pivot;

	ai = -1;
	sorted = (int *)malloc(sizeof(int) * argc);
	while (ai++ < argc)
		sorted[ai] = a[ai];
	pivot = selec_sort(sorted, argc);
	ai = argc;
	bi = 0;
	//if (is_sorted())
	// while ? 
	// check if sorted
	// make order(with pivot)
}

int main(int argc, char *argv[])
{
	int *a;
	int *b;
	long long tmp;
	int i;

	if (argc <= 1)
		ft_exit(a, b, 1);
	else
		argc--;
	a = (int *)malloc(sizeof(int) * argc);
	b = (int *)malloc(sizeof(int) * argc);
	
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp == -1 || tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(a, b, 1);
		a[argc - i - 1] = tmp;
		i++;
	}
	print(a, b, argc);
	if (argc == 2 || argc == 3 || argc == 5)
		push_swap_special(a, b, argc);
	else
		push_swap(a, b, argc);
	printf("\nfinal:\n");
	print(a, b, argc);
	return (ft_exit(a, b, 0));
}

