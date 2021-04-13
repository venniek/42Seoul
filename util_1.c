/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:23:28 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 16:23:34 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	ft_min(size_t a, long long b)
{
	if ((long long)a > b)
		return (b);
	else
		return (a);
}

long long	ft_max(long long a, long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t		ft_len(unsigned long n, int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

size_t		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int	atoi;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	atoi = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * atoi);
}
