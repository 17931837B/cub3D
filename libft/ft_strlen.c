#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	k;

	k = 0;
	while (*(str + k))
		k++;
	return (k);
}
