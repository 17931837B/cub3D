/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:47 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/20 21:27:47 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapcre2(t_cub3d *viw, char *str, int n, int *k)
{
	if (*(str + n) == 'N' || *(str + n) == 'E'
		|| *(str + n) == 'W' || *(str + n) == 'S')
		*(k + n) = 2;
	if (*(str + n) == 'N')
		viw->man.angle_h = 0;
	else if (*(str + n) == 'E')
		viw->man.angle_h = 90;
	else if (*(str + n) == 'S')
		viw->man.angle_h = 180;
	else if (*(str + n) == 'W')
		viw->man.angle_h = 270;
	else if (*(str + n) != '\n')
		return (1);
	return (0);
}

int	mapsetbyte(t_cub3d *viw, char *str, int n, int *k)
{
	if (*(str + n) == ' ')
		*(k + n) = -1;
	else if (*(str + n) == '0')
		*(k + n) = 0;
	else if (*(str + n) == '1')
		*(k + n) = 1;
	else
		return (mapcre2(viw, str, n, k));
	return (0);
}

int	countmap(t_cub3d *viw, char *fdr)
{
	int		fd;
	int		count;
	char	*str;

	fd = open(fdr, O_RDONLY);
	str = skip(fd);
	count = 0;
	while (str)
	{
		if (ft_strcmp(str, "\n"))
			count++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	viw->mapheight = count;
	close(fd);
	viw->map = (int **)malloc(sizeof(int *) * count);
	if (!viw->map)
		return (1);
	return (0);
}

int	set_manpos(t_cub3d *viw)
{
	int	count;
	int	n;
	int	m;

	count = 0;
	n = 0;
	while (n < viw->mapwidth)
	{
		m = 0;
		while (m < viw->mapheight)
		{
			if (viw->map[m][n] == 2)
			{
				viw->man.pos_x = n + 0.5;
				viw->man.pos_y = m + 0.5;
				count++;
			}
			m++;
		}
		n++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	mapcheck(t_cub3d *viw)
{
	int	n;
	int	m;

	if (mapch(viw))
		return (1);
	n = 0;
	while (n < viw->mapheight)
	{
		m = 0;
		while (m < viw->mapwidth)
		{
			if (ch(viw, m, n))
				return (1);
			m++;
		}
		n++;
	}
	return (0);
}
