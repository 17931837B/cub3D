#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	if (s == 0)
		return ;
	n = 0;
	while (*(s + n))
	{
		write(fd, s + n, 1);
		n++;
	}
}
