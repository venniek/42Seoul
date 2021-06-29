/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:38:40 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:40:35 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_strlen(const char *str)
{
	int			len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long		ft_atoi(t_stack *stack, const char *str, int *k)
{
	long long	atoi;
	int			i;
	int			sign;
	int			is;

	i = 0;
	sign = 1;
	is = 0;
	while (ft_strchr("\t\n\v\f\r ", str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	atoi = make_atoi(stack, str, &i);
	*k += i;
	return (sign * atoi);
}

long long		make_atoi(t_stack *stack, const char *str, int *i)
{
	long long	atoi;
	int			is;

	is = 0;
	atoi = 0;
	while (str[*i])
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			atoi = atoi * 10 + str[*i] - '0';
			is = 1;
		}
		else if (ft_strchr("\t\n\v\f\r ", str[*i]))
			break ;
		else
			ft_exit(stack, 1);
		(*i)++;
	}
	if (is == 0)
		ft_exit(stack, 1);
	return (atoi);
}

int				check_sort(t_stack *stack)
{
	int			i;

	if (stack->cnt <= 1)
		return (0);
	if (stack->ai != stack->cnt)
		return (1);
	i = -1;
	while (++i < stack->cnt)
	{
		if (stack->a[i] != stack->sorted[stack->cnt - 1 - i])
			return (1);
	}
	return (0);
}

void			sort_sort(int *sort, int len)
{
	int			i;
	int			k;
	int			min;
	int			tmp;

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
