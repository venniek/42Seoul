/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:57:02 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:57:04 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

long long	ft_atoi(t_stack *stack, const char *str)
{
	long long	atoi;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (ft_strchr("\t\n\v\f\r ", str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + str[i] - '0';
		else
			ft_exit(stack, 1);
		i++;
	}
	return (sign * atoi);
}

int check_sort(t_stack *stack)
{
	int i;

	if (stack->ai != stack->cnt)
		return (1);
	i = -1;
	while (++i < stack->cnt - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (1);
	}
	if (stack->a[i] != stack->sorted[0])
		return (1);
	return (0);
}