/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:58:26 by naykim            #+#    #+#             */
/*   Updated: 2021/01/07 18:07:37 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int					ft_atoi(const char *str)
{
	unsigned int	atoi;
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
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
	return (sign * (int)atoi);
}

int main()
{

	printf("%d\n", ft_atoi("2147483648"));
	printf("%d\n", ft_atoi("-2147483649"));

	printf("%d\n", atoi("2147483648"));
	printf("%d\n", atoi("-2147483649"));
	return 0;
}
