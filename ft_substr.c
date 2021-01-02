/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:36:48 by naykim            #+#    #+#             */
/*   Updated: 2021/01/02 18:15:55 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (i++ < start)
		s++;
	i = 0;
	while (s && i++ < len)
		*(str++) = *(s++);
	return (str);
}
