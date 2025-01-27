/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:20 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:20 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	free_and_close(int fd, char *line)
{
	if (line)
		free (line);
	close(fd);
}

void	copy_line(t_map_bb *map_list, int fd, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (line && j < map_list->v_len)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			map_list->map[j][i] = line[i];
			i++;
		}
		while (i < map_list->h_len - 1)
		{
			map_list->map[j][i] = ' ';
			i++;
		}
		map_list->map[j][i] = '\0';
		free(line);
		line = get_next_line(fd);
		j++;
	}
	map_list->map[j] = '\0';
	free_and_close(fd, line);
}

void	bb_create_map(t_map_bb *map_list, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line))
			break ;
		free (line);
	}
	copy_line(map_list, fd, line);
}
