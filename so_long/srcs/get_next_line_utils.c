#include "../includes/so_long.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

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
	while (s && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	char			*dst;
	size_t			i;

	i = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
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
