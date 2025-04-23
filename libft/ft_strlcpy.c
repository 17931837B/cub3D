#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	k;

	if (!src || !dest)
		return (0);
	k = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (k < n - 1 && *(src + k))
	{
		*(dest + k) = *(src + k);
		k++;
	}
	*(dest + k) = '\0';
	return (ft_strlen(src));
}
