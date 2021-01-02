/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:13:26 by naykim            #+#    #+#             */
/*   Updated: 2021/01/02 18:05:37 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_put(char *str, long long nbr)
{
	int sign;

	sign = 1;
	if (nbr < 0)
	{
		nbr =* -1;
		sign = -1;
	}
	while (nbr > 0)
	{
		*(str++) = nbr % 10;
		nbr =/ 10;
	}
	if (sign == -1)
		*(str++) = '-';
}

static void ft_swap(char *str)
{
	int len;
	int i;
	char tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

char *ft_itoa(int n)
{
	long long nbr;
	int i;
	char *str;

	i = 0;
	nbr = (long long)n;
	if (nbr < 0)
		nbr =* -1;
	while (nbr > 0)
	{
		nbr =/ 10;
		i++;
	}
	if (n < 0)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	ft_put(str, n);
	ft_swap(str);
	return (str);
}
