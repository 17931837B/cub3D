/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:44:59 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/15 23:44:59 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	util_n_e(t_man ray, int n)
{
	if (n == 1)
		return (ray.pos_y - ((int)(ray.pos_x + 1)
			- ray.pos_x) / ray.htan);
	if (n == 2)
		return (ray.pos_z - ((int)(ray.pos_x + 1)
			- ray.pos_x) * ray.vtan / ray.hsin);
	if (n == 3)
		return (ray.pos_x + (ray.pos_y
				- (int)ray.pos_y) * ray.htan);
	return (ray.pos_z - (ray.pos_y
			- (int)ray.pos_y) * ray.vtan / ray.hcos);
}

double	util_e_n(t_man ray, int n)
{
	if (n == 1)
		return (ray.pos_x + (ray.pos_y
				- (int)ray.pos_y) * ray.htan);
	if (n == 2)
		return (ray.pos_z - (ray.pos_y
				- (int)ray.pos_y) * ray.vtan / ray.hcos);
	if (n == 3)
		return (ray.pos_y - ((int)(ray.pos_x + 1)
			- ray.pos_x) / ray.htan);
	return (ray.pos_z - ((int)(ray.pos_x + 1)
		- ray.pos_x) * ray.vtan / ray.hsin);
}

double	util_e_s(t_man ray, int n)
{
	if (n == 1)
		return (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan);
	if (n == 2)
		return (ray.pos_z - (ray.pos_y
				- (int)ray.pos_y - 1) * ray.vtan / ray.hcos);
	if (n == 3)
		return (ray.pos_y - ((int)(ray.pos_x + 1)
			- ray.pos_x) / ray.htan);
	return (ray.pos_z - ((int)(ray.pos_x + 1)
		- ray.pos_x) * ray.vtan / ray.hsin);
}

double	util_s_e(t_man ray, int n)
{
	if (n == 1)
		return (ray.pos_y - ((int)(ray.pos_x + 1)
			- ray.pos_x) / ray.htan);
	if (n == 2)
		return (ray.pos_z - ((int)(ray.pos_x + 1)
			- ray.pos_x) * ray.vtan / ray.hsin);
	if (n == 3)
		return (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan);
	return (ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos);
}

double	util_s_w(t_man ray, int n)
{
	if (n == 1)
		return (ray.pos_y - ((int)(ray.pos_x) - ray.pos_x) / ray.htan);
	if (n == 2)
		return (ray.pos_z - ((int)(ray.pos_x)
			- ray.pos_x) * ray.vtan / ray.hsin);
	if (n == 3)
		return (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan);
	return (ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos);
}
