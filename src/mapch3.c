/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapch3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:42:33 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/20 23:42:33 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ue(t_cub3d *viw, int x, int y)
{
	if ((x != 0 && !(viw->map[y - 1][x - 1] == 1
			|| viw->map[y - 1][x - 1] == -1))
		|| !(viw->map[y - 1][x] == 1 || viw->map[y - 1][x] == -1))
		return (1);
	if (x != viw->mapwidth - 1 && !(viw->map[y - 1][x + 1] == 1
		|| viw->map[y - 1][x + 1] == -1))
		return (1);
	return (0);
}

int	hidari(t_cub3d *viw, int x, int y)
{
	if (!(viw->map[y][x - 1] == 1 || viw->map[y][x - 1] == -1))
		return (1);
	return (0);
}

int	migi(t_cub3d *viw, int x, int y)
{
	if (!(viw->map[y][x + 1] == 1 || viw->map[y][x + 1] == -1))
		return (1);
	return (0);
}

int	shita(t_cub3d *viw, int x, int y)
{
	if ((x != 0 && !(viw->map[y + 1][x - 1] == 1
			|| viw->map[y + 1][x - 1] == -1))
		|| !(viw->map[y + 1][x] == 1 || viw->map[y + 1][x] == -1))
		return (1);
	if (x != viw->mapwidth - 1 && !(viw->map[y + 1][x + 1] == 1
		|| viw->map[y + 1][x + 1] == -1))
		return (1);
	return (0);
}
