/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:14:12 by naykim            #+#    #+#             */
/*   Updated: 2021/01/23 16:55:12 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int c)
{
	int		len;

	len = 0;
	if (c < 0)
	{
		len++;
		c *= -1;
	}
	while (c > 0)
	{
		len++;
		c /= 10;
	}
	return (len);
}

static char	*make_itoa(char *s, int c, int len)
{
	int		i;

	if (c < 0)
	{
		c *= -1;
		s[0] = '-';
	}
	i = 0;
	while (c > 0)
	{
		s[len - i - 1] = c % 10 + '0';
		c /= 10;
		i++;
	}
	s[len] = '\0';
	return (s);
}

char		*ft_itoa(int c)
{
	char	*s;
	int		len;
	if (c == -2147483648)
		return (s = ft_strdup("-2147483648"));
	if (c == 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	len = ft_len(c);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	make_itoa(s, c, len);
	return (s);
}
