/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapch2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:36:00 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/20 23:36:00 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	top(t_cub3d *viw)
{
	int	n;

	n = 0;
	while (n < viw->mapwidth)
	{
		if (!(viw->map[0][n] == 1 || viw->map[0][n] == -1))
			return (1);
		n++;
	}
	return (0);
}

int	bot(t_cub3d *viw)
{
	int	n;

	n = 0;
	while (n < viw->mapwidth)
	{
		if (!(viw->map[viw->mapheight - 1][n] == 1
			|| viw->map[viw->mapheight - 1][n] == -1))
			return (1);
		n++;
	}
	return (0);
}

int	left(t_cub3d *viw)
{
	int	n;

	n = 0;
	while (n < viw->mapheight)
	{
		if (!(viw->map[n][0] == 1 || viw->map[n][0] == -1))
			return (1);
		n++;
	}
	return (0);
}

int	right(t_cub3d *viw)
{
	int	n;

	n = 0;
	while (n < viw->mapheight)
	{
		if (!(viw->map[n][viw->mapwidth - 1] == 1
			|| viw->map[n][viw->mapwidth - 1] == -1))
			return (1);
		n++;
	}
	return (0);
}
