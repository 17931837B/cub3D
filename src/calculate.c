/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:12:02 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/12 23:12:02 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calcangle_v(t_cub3d *viw, int y)
{
	double	ans;

	ans = ((double)viw->frame_height / 2 - y)
		* viw->const_fov / viw->frame_height;
	if (ans < 0)
		ans += 360;
	return (ans);
}

double	calcangle_h(t_cub3d *viw, int x)
{
	double	ans;

	ans = viw->man.angle_h + (x - (double)viw->frame_width / 2)
		* viw->const_fov / viw->frame_height;
	if (ans < 0)
		ans += 360;
	return (ans);
}

double	ftoradian(double angle)
{
	return (angle / 360 * 2 * M_PI);
}

int	get_monitor_pixel_color(t_cub3d *viw, double angle_h, double angle_v)
{
	t_man	ray_point;

	ray_point.pos_x = viw->man.pos_x;
	ray_point.pos_y = viw->man.pos_y;
	ray_point.pos_z = viw->man.pos_z;
	if (angle_h >= 360)
		angle_h -= 360;
	angle_h = ftoradian(angle_h);
	angle_v = ftoradian(angle_v);
	ray_point.angle_h = angle_h;
	ray_point.angle_v = angle_v;
	ray_point.htan = tan(angle_h);
	ray_point.hcos = cos(angle_h);
	ray_point.hsin = sin(angle_h);
	ray_point.vtan = tan(angle_v);
	ray_point.vsin = sin(angle_v);
	return (g_color(viw, ray_point));
}

int	monitor_pixelcolor(t_cub3d *viw, int x, int y)
{
	return (get_monitor_pixel_color(viw, calcangle_h(viw, x),
			calcangle_v(viw, y)));
}
