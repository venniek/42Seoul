#include "libft.h"

char* ft_strrchr(const char* str, int a)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		if (str[len - i - 1] == a)
			return (str[len - i - 1]);
		i++;
	}
	return (0);
}
