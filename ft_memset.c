/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:11:45 by naykim            #+#    #+#             */
/*   Updated: 2020/12/31 04:12:16 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*a;

	a = (unsigned char*)ptr;
	while (num-- > 0)
		*(ptr++) = (unsigned char)value;
	return (a);
}
