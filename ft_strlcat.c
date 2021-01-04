/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:55:44 by naykim            #+#    #+#             */
/*   Updated: 2021/01/04 20:15:47 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		k;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + ft_strlen(src));
	i = 0;
	k = 0;
	while (dst[i])
		i++;
	while (i < size - dstlen - 1 && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = 0;
	return (dstlen + ft_strlen(src));
}
