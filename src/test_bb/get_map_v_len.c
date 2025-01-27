/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_v_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:59 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:59 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

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
		if (line[0] == '\n')
			break ;
		v_len++;
		free (line);
	}
	if (line)
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
