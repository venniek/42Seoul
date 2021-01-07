/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:10:32 by naykim            #+#    #+#             */
/*   Updated: 2021/01/07 17:34:05 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	
	if (src[0] == '\0')
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (num == 0 || str1 == str2)
		return (str1);
	i = 0;
	while (num--)
		*(str1++) = *(str2++);
	return (dest);
}
