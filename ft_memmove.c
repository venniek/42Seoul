/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:36:36 by naykim            #+#    #+#             */
/*   Updated: 2020/12/31 04:11:31 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr1 > ptr2)
		while (i++ < len)
			ptr1[n - i] = ptr2[n - i];
	else
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	return (dest);
}
