/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:53:36 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:38:16 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_exit(t_stack *stack, int i)
{
	if (stack->a != 0)
		ft_intfree(stack->a);
	if (stack->b != 0)
		ft_intfree(stack->b);
	if (stack->sorted != 0)
		ft_intfree(stack->sorted);
	if (stack->pivot != 0)
		ft_intfree(stack->pivot);
	if (stack->last != 0)
		ft_strfree(stack->last);
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_intfree(int *num)
{
	if (num == 0)
		return ;
	free(num);
	num = 0;
}

void	ft_strfree(char *str)
{
	if (str == 0)
		return ;
	free(str);
	str = 0;
}
