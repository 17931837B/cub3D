#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			k;
	unsigned char	*box;

	box = (unsigned char *)buf;
	k = 0;
	while (k < n)
	{
		if (*(box + k) == (unsigned char)ch)
			return (box + k);
		k++;
	}
	return (0);
}
