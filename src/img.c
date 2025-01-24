/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:46 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/14 22:15:46 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//x_pos,y_poxから画像を取得。tmpは向き。
int	yy_img(t_cub3d *viw, t_man ray, int tmp)
{
	int	x;
	int	y;

	if (tmp)
	{
		x = viw->west.width * (1 - (ray.pos_y - (int)ray.pos_y));
		y = viw->west.height * ray.pos_z;
		return (get_pixel_color(&viw->west, x, y));
	}
	else
	{
		x = viw->east.width * (ray.pos_y - (int)ray.pos_y);
		y = viw->east.height * ray.pos_z;
		return (get_pixel_color(&viw->east, x, y));
	}
}

int	xx_img(t_cub3d *viw, t_man ray, int tmp)
{
	int	x;
	int	y;

	if (tmp)
	{
		x = viw->north.width * (ray.pos_x - (int)ray.pos_x);
		y = viw->north.height * ray.pos_z;
		return (get_pixel_color(&viw->north, x, y));
	}
	else
	{
		x = viw->south.width * (1 - (ray.pos_x - (int)ray.pos_x));
		y = viw->south.height * ray.pos_z;
		return (get_pixel_color(&viw->south, x, y));
	}
}

int	isexternal(t_cub3d *viw, int y, int x, int *color)
{
	if (x >= viw->mapwidth || x < 0 || y >= viw->mapheight || y < 0)
	{
		*color = 0;
		return (1);
	}
	return (0);
}

int	y_img(t_cub3d *viw, t_man ray, int tmp, int *color)
{
	if (ray.pos_z <= 0)
	{
		*color = (viw->ceiling.red << 16)
			| (viw->ceiling.green << 8) | viw->ceiling.blue;
		return (0);
	}
	if (ray.pos_z >= 1)
	{
		*color = (viw->floor.red << 16)
			| (viw->floor.green << 8) | viw->floor.blue;
		return (0);
	}
	if (isexternal(viw, (int)ray.pos_y, (int)ray.pos_x - tmp, color))
		return (0);
	if (viw->map[(int)ray.pos_y][(int)ray.pos_x - tmp] == OBJECT)
	{
		*color = yy_img(viw, ray, tmp);
		return (0);
	}
	return (3);
}

int	x_img(t_cub3d *viw, t_man ray, int tmp, int *color)
{
	if (ray.pos_z <= 0)
	{
		*color = (viw->ceiling.red << 16)
			| (viw->ceiling.green << 8) | viw->ceiling.blue;
		return (0);
	}
	if (ray.pos_z >= 1)
	{
		*color = (viw->floor.red << 16)
			| (viw->floor.green << 8) | viw->floor.blue;
		return (0);
	}
	if (isexternal(viw, (int)ray.pos_y - tmp, (int)ray.pos_x, color))
		return (0);
	if (viw->map[(int)ray.pos_y - tmp][(int)ray.pos_x] == OBJECT)
	{
		*color = xx_img(viw, ray, tmp);
		return (0);
	}
	return (2);
}
