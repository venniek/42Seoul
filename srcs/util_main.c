/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:19:41 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 15:27:17 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_one_a(t_stack *stack)
{
	int	i;
	int	*newa;

	newa = (int *)malloc(sizeof(int) * (stack->ai + 1));
	i = -1;
	while (++i < stack->ai)
		newa[i] = stack->a[i];
	ft_intfree(stack->a);
	stack->a = newa;
}

void	swap_stack(int *a, int len)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < len / 2)
	{
		tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp;
	}
}

void	malloc_all(t_stack *stack)
{
	int	i;

	stack->b = (int *)malloc(sizeof(int) * stack->cnt);
	stack->sorted = (int *)malloc(sizeof(int) * stack->cnt);
	i = -1;
	while (++i < stack->cnt)
		stack->sorted[i] = stack->a[i];
	selec_sort(stack);
	make_div(stack);
	stack->pivot = (int *)malloc(sizeof(int) * stack->div);
}
