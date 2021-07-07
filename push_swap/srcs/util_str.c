/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:54:54 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:40:02 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

char	*ft_strjoin(char **s1, char *s2)
{
	char			*str;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (s2 == 0)
		return (NULL);
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (k < len1)
		str[i++] = (*s1)[k++];
	k = 0;
	while (k < len2)
		str[i++] = s2[k++];
	str[i] = '\0';
	free(*s1);
	return (str);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char			*str;
	int				i;

	if (s == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (ft_strlen(s) <= start)
	{
		str[0] = '\0';
		return (str);
	}
	while (i++ < start)
		s++;
	i = 0;
	while (s && i < (int)len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
