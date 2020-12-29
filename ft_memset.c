#include "libft.h"

void *ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *a;

	a = (unsigned char*)ptr;
	while (num-- > 0)
		*(ptr++) = (unsigned char)value;
	return (a);
}
