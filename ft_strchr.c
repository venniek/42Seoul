#include "libft.h"

char* ft_strchr(const char* str, int a)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (str[i]);
		i++;
	}
	return (0);
}
