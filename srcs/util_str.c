/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:54:54 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 19:55:06 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strchr(const char *str, int a)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < ft_strlen(str) + 1)
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}
