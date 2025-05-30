#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);

typedef struct s_point
{
	int		ch;
	int		fd;
	char	*line;
}	t_point;
char	*get_next_line(int fd);
char	*catstrlen(char *dest, char *src, ssize_t len);

#endif
