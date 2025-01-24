/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:01:30 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/12 22:01:30 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keymove(int keycode, t_cub3d *viw)
{
	if (keycode == KEY_W)
		push_w(viw);
	else if (keycode == KEY_A)
		push_a(viw);
	else if (keycode == KEY_S)
		push_s(viw);
	else if (keycode == KEY_D)
		push_d(viw);
	else if (keycode == KEY_L)
		push_l(viw);
	else if (keycode == KEY_R)
		push_r(viw);
	else if (keycode == KEY_ESC)
		push_esc(viw);
	return (0);
}

void	push_w(t_cub3d *viw)
{
	double	x;
	double	y;
	double	angle;

	angle = ftoradian(viw->man.angle_h);
	x = viw->man.pos_x + PLAYER_MOVE_SPEED * sin(angle);
	y = viw->man.pos_y - PLAYER_MOVE_SPEED * cos(angle);
	if (viw->map[(int)y][(int)x] == OBJECT)
		return ;
	viw->man.pos_x = x;
	viw->man.pos_y = y;
	first_img(viw);
}

void	push_a(t_cub3d *viw)
{
	double	x;
	double	y;
	double	angle;

	angle = ftoradian(viw->man.angle_h) + M_PI * 3 / 2;
	x = viw->man.pos_x + PLAYER_MOVE_SPEED * sin(angle);
	y = viw->man.pos_y - PLAYER_MOVE_SPEED * cos(angle);
	if (viw->map[(int)y][(int)x] == OBJECT)
		return ;
	viw->man.pos_x = x;
	viw->man.pos_y = y;
	first_img(viw);
}

void	push_s(t_cub3d *viw)
{
	double	x;
	double	y;
	double	angle;

	angle = ftoradian(viw->man.angle_h) + M_PI;
	x = viw->man.pos_x + PLAYER_MOVE_SPEED * sin(angle);
	y = viw->man.pos_y - PLAYER_MOVE_SPEED * cos(angle);
	if (viw->map[(int)y][(int)x] == OBJECT)
		return ;
	viw->man.pos_x = x;
	viw->man.pos_y = y;
	first_img(viw);
}

void	push_d(t_cub3d *viw)
{
	double	x;
	double	y;
	double	angle;

	angle = ftoradian(viw->man.angle_h) + M_PI / 2;
	x = viw->man.pos_x + PLAYER_MOVE_SPEED * sin(angle);
	y = viw->man.pos_y - PLAYER_MOVE_SPEED * cos(angle);
	if (viw->map[(int)y][(int)x] == OBJECT)
		return ;
	viw->man.pos_x = x;
	viw->man.pos_y = y;
	first_img(viw);
}
