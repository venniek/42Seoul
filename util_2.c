/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:17:09 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 04:17:32 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void		ft_putnbr(long long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void		ft_putnbr_hex(unsigned long n, char c)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, c);
	if (c == 'p' || c == 'x')
		ft_putchar(HEX_L[n % 16]);
	else if (c == 'X')
		ft_putchar(HEX_U[n % 16]);
}

char		*ft_strchr(char *str, int a)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < ft_strlen(str) + 1)
	{
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
