/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:53:36 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:53:44 by naykim           ###   ########.fr       */
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

void	sort_sort(int *sort, int len)
{
	int	i;
	int	k;
	int	min;
	int	tmp;

	i = -1;
	while (++i < len - 1)
	{
		min = i;
		k = i;
		while (++k < len)
		{
			if (sort[min] > sort[k])
				min = k;
		}
		tmp = sort[min];
		sort[min] = sort[i];
		sort[i] = tmp;
	}
}

int		merge_order(t_stack *stack, char *str)
{
	if (stack->last == 0)
		return (0);
	if (ft_strcmp(stack->last, "sa") == 0 && ft_strcmp(str, "sb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "sb") == 0 && ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(stack->last, "ra") == 0 && ft_strcmp(str, "rb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rb") == 0 && ft_strcmp(str, "ra") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rra") == 0 && ft_strcmp(str, "rrb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rrb") == 0 && ft_strcmp(str, "rra") == 0)
		return (1);
	return (0);
}

void print_order(t_stack *stack)
{
	if (stack->last == 0)
		return ;
	ft_putstr_fd(stack->last, 1);
	ft_putstr_fd("\n", 1);
}
