/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:55:44 by naykim            #+#    #+#             */
/*   Updated: 2020/12/31 04:14:16 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		k;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	k = 0;
	if (dstlen > size)
		return (size + ft_strlen(src));
	while (dst[i])
		i++;
	while (i + dstlen + 1 < size && src[k])
		dst[i++] = src[k++];
	dst[i] = 0;
	return (dstlen + ft_strlen(src));
}
