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
		if (!is_map(line))
			break ;
		h_len = get_long_len(h_len, line);
		free (line);
	}
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

char	**get_map(char *path)
{
	int		v_len;
	int		h_len;
	char	**map;
	int		i;

	v_len = get_map_v_len(path);
	h_len = get_map_h_len(path);
	map = (char **)malloc(sizeof(char *) * v_len);
	i = 0;
	while (i < v_len)
	{
		map[i] = ft_calloc(h_len, sizeof(char));
		i++;
	}
	printf("v_len: %d\n", v_len);
	printf("h_len: %d\n", h_len);
	return (map);
}

void	copy_line(char **map, int fd, char *line, int h_len)
{
	int	i;
	int	j;

	j = 0;
	while (line && is_map(line))
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			map[j][i] = line[i];
			i++;
		}
		while (i < h_len - 1)
		{
			map[j][i] = ' ';
			i++;
		}
		map[j][i] = '\0';
		free(line);
		line = get_next_line(fd);
		j++;
	}
	if (line)
		free (line);
	close(fd);
}

void	bb_create_map(char **map, char *file_path)
{
	int		fd;
	char	*line;
	int		h_len;

	fd = open(file_path, O_RDONLY);
	h_len = get_map_h_len(file_path);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line))
			break ;
		free (line);
	}
	copy_line(map, fd, line, h_len);
}

bool	is_wrong_map(char *path)
{
	char	**map;

	map = get_map(path);
	bb_create_map(map, path);
	if (map[0][0] == map[0][33])
		printf("hello\n");
	printf("map[0][0] :%c\n", map[0][0]);
	printf("map[0][33]:%c\n", map[0][33]);
	printf("map[0][32]:%c\n", map[0][32]);
	int i;
	i = 0;
	while (i < 14)
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
    free(map);
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
