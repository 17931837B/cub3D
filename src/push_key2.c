#include "cub3d.h"

void	push_r(t_cub3d *viw)
{
	viw->man.angle_h += PLAYER_ANGLE_SPEED;
	if (viw->man.angle_h >= 360)
		viw->man.angle_h -= 360;
	first_img(viw);
}

void	push_l(t_cub3d *viw)
{
	viw->man.angle_h -= PLAYER_ANGLE_SPEED;
	if (viw->man.angle_h < 0)
		viw->man.angle_h += 360;
	first_img(viw);
}
