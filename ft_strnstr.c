#include "libft.h"

char* ft_strnstr(const char* str, const char* fin, size_t len)
{
	int i;
	int k;
	int finlen;

	i = 0;
	finlen = ft_strlen(fin);
	if (finlen == 0)
		return (str);
	while ( i < len - finlen)
	{
		k = 0;
		while (str[i + k] == fin[k])
		{
			k++;
			if (fin[k] == 0)
				return (str[i]);
		}
		i++;
	}
	return (0);
}
