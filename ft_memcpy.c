#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (num-- > 0)
		*(str1++) = *(str2++);
	return (dest);
}
