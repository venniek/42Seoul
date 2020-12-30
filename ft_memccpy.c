/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:08:49 by naykim            #+#    #+#             */
/*   Updated: 2020/12/31 04:09:18 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	*str;

	str = (size_t *)dest;
	while (n-- > 0 && *(src++) != 0)
	{
		str = src;
		str++;
		if (src == c)
			break ;
	}
	str = 0;
	return (str++);
}
