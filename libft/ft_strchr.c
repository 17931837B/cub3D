#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	n;

	if (str == 0)
		return (0);
	n = 0;
	while (*(str + n))
	{
		if (*(str + n) == (char)c)
			return ((char *)str + n);
		n++;
	}
	if (*(str + n) == (char)c)
		return ((char *)str + n);
	return (0);
}
