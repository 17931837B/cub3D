/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:26 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:26 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	get_long_len(int h_len, char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len >= h_len)
		return (line_len);
	return (h_len);
}

int	count_h_len(int fd, char *line)
{
	int	h_len;

	h_len = 0;
	if (!line)
	{
		close(fd);
		return (0);
	}
	free (line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			break ;
		h_len = get_long_len(h_len, line);
		free (line);
	}
	if (line)
		free (line);
	close (fd);
	return (h_len);
}

int	get_map_h_len(char *file_path)
{
	int		fd;
	char	*line;
	int		h_len;

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
	h_len = count_h_len(fd, line);
	return (h_len);
}

void	get_map(char *path, t_map_bb *map_list)
{
	int		i;

	map_list->v_len = get_map_v_len(path);
	map_list->h_len = get_map_h_len(path);
	if (!map_list->v_len || !map_list->h_len)
	{
		map_list->map = NULL;
		printf("Error\nCan't create map.\n");
		return ;
	}
	map_list->map = (char **)malloc(sizeof(char *) * (map_list->v_len + 1));
	i = 0;
	while (i < map_list->v_len)
	{
		map_list->map[i] = ft_calloc(map_list->h_len + 1, sizeof(char));
		i++;
	}
}
