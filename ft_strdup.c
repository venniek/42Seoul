/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:16:43 by naykim            #+#    #+#             */
/*   Updated: 2020/12/31 04:13:26 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
	{
		while (s)
			*(dst++) = *(s++);
		return (dst);
	}
	return (NULL);
}
