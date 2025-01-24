#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3d.h"

void	init_check_list(t_check_bb *check_list)
{
	check_list->F = 0;
	check_list->C = 0;
	check_list->NO = 0;
	check_list->WE = 0;
	check_list->SO = 0;
	check_list->EA = 0;
}

void	check_list_update(char *line, t_check_bb **check_list)
{
	if (line[0] == 'F')
		(*check_list)->F++;
	if (line[0] == 'C')
		(*check_list)->C++;
	if (line[0] == 'N' && line[1] == 'O')
		(*check_list)->NO++;
	if (line[0] == 'W' && line[1] == 'E')
		(*check_list)->WE++;
	if (line[0] == 'S' && line[1] == 'O')
		(*check_list)->SO++;
	if (line[0] == 'E' && line[1] == 'A')
		(*check_list)->EA++;
}

bool	is_duplication(t_check_bb *check_list)
{
	if (check_list->F > 1 || check_list->C > 1 || check_list->NO > 1 || check_list->WE > 1 || check_list->SO > 1 || check_list->EA > 1)
		return (true);
	return (false); 
}

bool	is_correct_list(t_check_bb *check_list, char *line)
{
	if (is_duplication(check_list))
	{
		free(line);
		free(check_list);
		printf("Error\nDuplicate elements.\n");
		return (false);
	}
	if (is_wrong_color(line))
	{
		free(line);
		free(check_list);
		return (false);
	}
	return (true);
}

bool	set_bb(char *file_path)
{
	int			fd;
	char		*line;
	t_check_bb	*check_list;

	fd = open(file_path, O_RDONLY);
	check_list = malloc(sizeof(t_check_bb)); 
	if (!check_list)
	{
		printf("Error\nMemory allocation failed\n");
		return (true);
	}
	init_check_list(check_list);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_list_update(line, &check_list);
		if (!is_correct_list(check_list, line))
			return (true);
		free(line);
	}
	free(check_list);
	close(fd);
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
	return (false);
}
