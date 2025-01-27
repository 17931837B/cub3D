/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:54 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:54 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
