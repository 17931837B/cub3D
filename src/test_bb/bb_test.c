#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3d.h"

bool	set_bb(char *file_path)
{
	int			fd;
	char		*line;
	t_check_bb	*check_list;

	check_list = init_check_list();
	if (!check_list)
		return (true);
	if (!check_list)
		return (true);
	fd = open(file_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_list_update(line, &check_list);
		if (!check_color(line, check_list, fd))
			return (true);
		free(line);
	}
	close(fd);
	if (!is_correct_list(check_list, line))
		return (true);
	free(check_list);
	return (false);
}

bool	is_s1(char c)
{
	if (c == ' ' || c == '1')
		return (true);
	return (false);
}

bool	is_around_s1(char **map, int i, int j)
{
	if (is_s1(map[i - 1][j - 1]) && is_s1(map[i][j - 1]) && is_s1(map[i + 1][j - 1])
		&& is_s1(map[i - 1][j]) && is_s1(map[i + 1][j])
		&& is_s1(map[i - 1][j + 1]) && is_s1(map[i][j + 1]) && is_s1(map[i + 1][j + 1]))
		return (true);
	return (false);
}

bool	check_outside(t_map_bb *map_list)
{
	int	i;

	i = 0;
	while(map_list->map[0][i])
	{
		if (!is_s1(map_list->map[0][i]) || !is_s1(map_list->map[map_list->v_len - 1][i]))
			return (true);
		i++;
	}
	i = 0;
	while(map_list->map[i])
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
	while(map[i])
	{
		j = 0;
		while(map[i][j])
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

bool	is_wrong_map(char *path)
{
	t_map_bb	*map_list;
	bool		is_ok;

	map_list = malloc(sizeof(t_map_bb));
	get_map(path, map_list);
	if (!map_list->map)
	{
		free(map_list);
		return (true);
	}
	bb_create_map(map_list, path);
	is_ok = check_map(map_list);
	free_box(map_list->map);
	free(map_list);
	if (is_ok)
		return (false);
	printf("Error\nCan't create map.\n");
	return (true);
}

bool	test_bb(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nArgument Error\n");
		return (true);
	}
	if (name_check(av[1]) || open_check(av[1]))
		return (true);
	if (set_bb(av[1]))
		return (true);
	if (is_wrong_map(av[1]))
		return (true);
	return (false);
}
