/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_CF_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:39:30 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:39:30 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	free_box(char **box)
{
	int	i;

	i = 0;
	while (box[i])
	{
		free(box[i]);
		i++;
	}
	free(box);
}

bool	is_num(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] != '\n' && (!ft_isdigit(list[i][j]) || j > 3))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_wrong_val(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	if (i != 3 || !is_num(list) || list[2][0] == '\n')
	{
		printf("Error\nColor value wrong.\n");
		free_box(list);
		return (true);
	}
	if ((0 <= ft_atoi(list[0])) && (ft_atoi(list[0]) <= 255)
		&& (0 <= ft_atoi(list[1])) && (ft_atoi(list[1]) <= 255)
		&& (0 <= ft_atoi(list[2])) && (ft_atoi(list[2]) <= 255))
	{
		free_box(list);
		return (false);
	}
	printf("Error\nColor value over.\n");
	free_box(list);
	return (true);
}

bool	is_wrong_color(char *line)
{
	char	**box;
	char	**box2;

	if ((line[0] == 'F' || line[0] == 'C'))
	{
		if (line[1] != ' ')
		{
			printf("Error\nColor value wrong.\n");
			return (true);
		}
		box = ft_split(line, ' ');
		if (!(box[1] && !box[2]))
		{
			free_box (box);
			return (true);
		}
		free (box[0]);
		box2 = ft_split(box[1], ',');
		free (box[1]);
		free (box);
		if (is_wrong_val(box2))
			return (true);
	}
	return (false);
}

bool	check_color(char *line, t_check_bb *check_list, int fd)
{
	if (is_wrong_color(line))
	{
		free(line);
		free(check_list);
		close(fd);
		return (false);
	}
	return (true);
}
