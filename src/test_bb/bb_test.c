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

bool	is_map(char *line)
{
	int	i;

	if (line[0] != ' ' && line[0] != '1')
		return (false);
	i = 1;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'W'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	count_v_len(int fd, char *line)
{
	int	v_len;

	v_len = 1;
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
		if (!is_map(line))
			break ;
		v_len++;
		free (line);
	}
	free (line);
	close (fd);
	return (v_len);
}

int	get_map_v_len(char *file_path)
{
	int		fd;
	char	*line;
	int		v_len;

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
	v_len = count_v_len(fd, line);
	return (v_len);
}

char	**get_map(char *path)
{
	int		v_len;
	// int		h_len;

	v_len = get_map_v_len(path);
	printf("v_len: %d\n", v_len);
	return (NULL);
}

bool	is_wrong_map(char *path)
{
	char	**map;

	map = get_map(path);
	if (map)
		return (true);
	return (false);
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
