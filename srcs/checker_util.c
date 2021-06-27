#include "../push_swap.h"

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