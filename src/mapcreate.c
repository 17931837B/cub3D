/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:08:28 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/20 21:08:28 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iscolor(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "WE ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2)
		|| !ft_strcmp(str, "\n"))
		return (1);
	return (0);
}

char	*skip(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (iscolor(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

int	mapset(t_cub3d *viw, char *str, int len, int t)
{
	int	*k;
	int	n;

	if (!ft_strcmp("\n", str))
		return (len);
	if (!len)
		len = ft_strlen(str);
	if (len != (int)ft_strlen(str))
		return (-1);
	k = (int *)malloc(sizeof(int) * ft_strlen(str));
	if (!k)
		return (-1);
	viw->map[t] = k;
	n = 0;
	while (n < len)
	{
		if (mapsetbyte(viw, str, n, k))
			return (-1);
		n++;
	}
	return (len);
}

int	mapcre(t_cub3d *viw, char *s)
{
	int		n;
	int		len;
	char	*str;
	int		fd;

	fd = open(s, O_RDONLY);
	lastft(&n, &len, &str, &fd);
	while (str)
	{
		len = mapset(viw, str, len, n);
		if (len == -1)
		{
			free(str);
			return (1);
		}
		free(str);
		str = get_next_line(fd);
		n++;
	}
	if (str)
		free(str);
	viw->mapwidth = len - 1;
	close(fd);
	return (0);
}

int	mapcreated(t_cub3d *viw, char *str)
{
	if (countmap(viw, str) || mapcre(viw, str))
		return (1);
	return (0);
}
