/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:46:28 by naykim            #+#    #+#             */
/*   Updated: 2021/01/04 17:47:40 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	size_t			i;
	size_t			k;
	char			*str;

	i = 0; k = 0;
	len1 = (unsigned int)ft_strlen(s1);
	len2 = (unsigned int)ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (k < len1)
	{
		str[i] = s1[k];
		i++;
		k++;
	}
	k = 0;
	while (k < len2)
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = '\0';
	return (str);
}
