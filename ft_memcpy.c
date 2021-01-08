/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:10:32 by naykim            #+#    #+#             */
/*   Updated: 2021/01/08 18:02:34 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
