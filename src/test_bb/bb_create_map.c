#include "cub3d.h"

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
	if (line)
		free (line);
	close(fd);
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