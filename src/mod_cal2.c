/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:28:44 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/14 22:28:44 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d_tuning(t_man *ray, int flag)
{
	if (flag == 2 || flag == 3)
	{
		ray->pos_x += 0.00001 * ray->hsin;
		ray->pos_y -= 0.00001 * ray->hcos;
		ray->pos_z += 0.00001 * ray->vsin;
	}
}

int	g_color_s_w(t_cub3d *viw, t_man ray)
{
	int	flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1)
			* ray.htan <= (int)ray.pos_x)
		{
			ray.pos_y = util_s_w(ray, 1);
			ray.pos_z = util_s_w(ray, 2);
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_x = util_s_w(ray, 3);
			ray.pos_z = util_s_w(ray, 4);
			ray.pos_y = (int)ray.pos_y + 1;
			flag = x_img(viw, ray, 0, &color);
		}
	}
	return (color);
}

int	g_color_w_s(t_cub3d *viw, t_man ray)
{
	int	flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x - ray.pos_x)
			/ ray.htan >= (int)ray.pos_y + 1)
		{
			ray.pos_x = util_w_s(ray, 1);
			ray.pos_z = util_w_s(ray, 2);
			ray.pos_y = (int)ray.pos_y + 1;
			flag = x_img(viw, ray, 0, &color);
		}
		else
		{
			ray.pos_y = util_w_s(ray, 3);
			ray.pos_z = util_w_s(ray, 4);
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
	}
	return (color);
}

int	g_color_w_n(t_cub3d *viw, t_man ray)
{
	int	flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x - ray.pos_x)
			/ ray.htan <= (int)ray.pos_y)
		{
			ray.pos_x = util_w_n(ray, 1);
			ray.pos_z = util_w_n(ray, 2);
			ray.pos_y = (int)ray.pos_y;
			flag = x_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_y = util_w_n(ray, 3);
			ray.pos_z = util_w_n(ray, 4);
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
	}
	return (color);
}

int	g_color_n_w(t_cub3d *viw, t_man ray)
{
	int	flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y)
			* ray.htan <= (int)ray.pos_x)
		{
			ray.pos_y = util_n_w(ray, 1);
			ray.pos_z = util_n_w(ray, 2);
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_x = util_n_w(ray, 3);
			ray.pos_z = util_n_w(ray, 4);
			ray.pos_y = (int)ray.pos_y;
			flag = x_img(viw, ray, 1, &color);
		}
	}
	return (color);
}
