/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:16:26 by naykim            #+#    #+#             */
/*   Updated: 2021/01/04 17:18:28 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int a)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		s = (char *)str;
		if (s[len - i] == a)
			return (&s[len - i]);
		i++;
	}
	return (0);
}
