/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:48:30 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 21:48:30 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	len0(int len, char *buf, char **line, t_point *ch)
{
	int	n;

	n = 0;
	while (*(buf + n + len))
	{
		*(buf + n) = *(buf + n + len);
		n++;
	}
	*(buf + n) = '\0';
	n = 0;
	while (*(buf + n) != '\n' && *(buf + n))
		n++;
	*line = catstrlen(*line, buf, n + 1);
	if (!*(buf + n))
		return (0);
	ch->ch = 0;
	return (n + 1);
}

int	len1(int fd, char *buf, char **line, t_point *ch)
{
	int	len;
	int	n;

	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
	{
		ch->ch = 0;
		return (len);
	}
	*(buf + len) = '\0';
	n = 0;
	while (*(buf + n) && *(buf + n) != '\n')
		n++;
	if (*(buf + n) == '\n' || n != BUFFER_SIZE)
		ch->ch = 0;
	*line = catstrlen(*line, buf, n + 1);
	if (n == BUFFER_SIZE || (n != BUFFER_SIZE && *(buf + n) != '\n'))
		return (0);
	return (n + 1);
}

char	*get_next_line(int fd)
{
	t_point		k;
	t_point		*ch;
	static int	len;
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	ch = &k;
	ch->ch = 1;
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (0);
	*line = '\0';
	while (ch->ch && line)
	{
		if (len > 0)
			len = len0(len, buf, &line, ch);
		else
			len = len1(fd, buf, &line, ch);
	}
	if (!line || *line == '\0' || len < 0)
	{
		free(line);
		return (0);
	}
	return (line);
}

// #include <stdio.h>
// int	main()
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)) != 0)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 	}
// 	close(fd);
// }
