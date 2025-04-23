#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			k;
	unsigned char	*box;
	unsigned char	*bot;

	box = (unsigned char *)buf1;
	bot = (unsigned char *)buf2;
	k = 0;
	while (k < count)
	{
		if (*(box + k) != *(bot + k))
			return (*(box + k) - *(bot + k));
		k++;
	}
	return (0);
}
