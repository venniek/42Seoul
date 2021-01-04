/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:54:47 by naykim            #+#    #+#             */
/*   Updated: 2021/01/04 18:13:47 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int a)
{
	size_t	i;
	char	*s;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		s = (char *)str;
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
