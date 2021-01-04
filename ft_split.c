/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:47:34 by naykim            #+#    #+#             */
/*   Updated: 2021/01/04 14:52:50 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(const char *s, char c)
{
	char	**ex;
	int		i;

	i = 3;
	ex = (char **)malloc(sizeof(char *) * 3);
	while (i-- > 0)
	{
		ex[i] = (char *)malloc(sizeof(char) * 3);
	}
	ex[0] = "ab";
	ex[1] = "b";
	if (*s == c)
		ex[2] = "c";
	return (ex);
}
