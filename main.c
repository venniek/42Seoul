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





/*
void push_swap(int *a, int *b)
{

}

*/

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
	//push_swap(a, b);
	return (ft_exit(a, b, 0));
}
