/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:39:43 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:39:43 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

bool	check_outside(t_map_bb *map_list)
{
	int	i;

	i = 0;
	while (map_list->map[0][i])
	{
		if (!is_s1(map_list->map[0][i])
			|| !is_s1(map_list->map[map_list->v_len - 1][i]))
			return (true);
		i++;
	}
	i = 0;
	while (map_list->map[i])
	{
		if (!is_s1(map_list->map[i][0]))
			return (true);
		i++;
	}
	return (false);
}

bool	check_wall(t_map_bb *map_list)
{
	char	**map;
	int		i;
	int		j;

	map = map_list->map;
	if (check_outside(map_list))
		return (true);
	i = 1;
	while (i < map_list->v_len - 1)
	{
		j = 1;
		while (j < map_list->h_len - 2)
		{
			if (map[i][j] == ' ' && !is_around_s1(map, i, j))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	correct_ps(char **map)
{
	int	i;
	int	j;
	int	ps;

	ps = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'E')
				ps++;
			j++;
		}
		i++;
	}
	if (ps == 1)
		return (true);
	return (false);
}

bool	check_chara(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'W' && map[i][j] != 'S'
				&& map[i][j] != 'E')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_map(t_map_bb *map_list)
{
	if (check_chara(map_list->map))
		return (false);
	if (check_wall(map_list))
		return (false);
	if (!correct_ps(map_list->map))
		return (false);
	return (true);
}
