#include "libft.h"

size_t strlcat(char* dst, const char* src, size_t size)
{
	int i;
	int k;
	int dstori;

	dstori = ft_strlen(dst);

	i = 0;
	k = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (dstori > size)
		return (size + ft_strlen(src));
	while (dst[i])
		i++;
	while (i - dstori < size - 1 && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = 0;

	return (dstori + ft_strlen(src));

