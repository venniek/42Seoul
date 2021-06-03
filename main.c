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




void print(int *a, int *b)
{
	int i = 0;
	printf("\na: ");
	while (a[i])
	{
		printf("%d ", a[i]);
		i++;
	}
	i = 0;
	printf("\nb: ");
	while (b[i])
	{
		printf("%d ", b[i]);
		i++;
	}
	printf("\n");
}

void push_swap(int *a, int *b, int argc)
{
	int ai;
	int bi;

	ai = argc - 1;
	bi = 0;
	while (1)
	{
		if (is_ascending(a, argc) == 0)
			return ;
		
	}
	
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
	b = (int *)malloc(sizeof(int) * argc + 1);
	i = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp == -1 || tmp >= 2147483648 || tmp < -2147483648)
			ft_exit(a, b, 1);
		a[argc - i - 1] = tmp;
		i++;
	}
	//push_swap(a, b, argc);
	return (ft_exit(a, b, 0));
}

