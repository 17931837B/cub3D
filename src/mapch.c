/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:34:26 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/20 23:34:26 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapch(t_cub3d *viw)
{
	if (top(viw) || left(viw) || right(viw) || bot(viw))
		return (1);
	return (0);
}

int	ch(t_cub3d *viw, int x, int y)
{
	if (viw->map[y][x] == -1)
	{
		if (y != 0 && ue(viw, x, y))
			return (1);
		if (x != 0 && hidari(viw, x, y))
			return (1);
		if (x != viw->mapwidth - 1 && migi(viw, x, y))
			return (1);
		if (y != viw->mapheight - 1 && shita(viw, x, y))
			return (1);
	}
	return (0);
}
