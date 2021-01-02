/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:46:28 by naykim            #+#    #+#             */
/*   Updated: 2021/01/02 18:10:31 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	size_t			i;
	char			*str;

	len1 = (unsigned int)ft_strlen(s1);
	len2 = (unsigned int)ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i++ < len1)
		*(str++) = *(s1++);
	while (i++ < len2)
		*(str++) = *(s2++);
	str[i] = '\0';
	return (str);
}
