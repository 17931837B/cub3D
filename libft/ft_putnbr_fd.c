#include "libft.h"

static void	set(long k, int fd)
{
	char	c;

	if (k < 10)
	{
		c = k + '0';
		write(fd, &c, 1);
		return ;
	}
	set(k / 10, fd);
	c = k % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	k;

	k = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		k = -k;
	}
	set(k, fd);
}

// int	main()
// {
// 	ft_putnbr_fd(-2147483648, 1);
// }
