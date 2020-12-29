#include "libft.h"

int ft_strncmp(const char* str1, const char* str2, size_t n)
{
	int i;

	i = 0;
	while (i < n && str1[i] != 0 && str2[i] != 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	if (str1[i] != str2[i] && i != n)
		return (str1[i] - str2[i]);
	return (0);
}
