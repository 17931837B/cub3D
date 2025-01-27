/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_list_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:30 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:30 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_check_bb	*init_check_list(void)
{
	t_check_bb	*check_list;

	check_list = malloc(sizeof(t_check_bb));
	if (!check_list)
	{
		printf("Error\nMemory allocation failed\n");
		return (NULL);
	}
	check_list->F = 0;
	check_list->C = 0;
	check_list->NO = 0;
	check_list->WE = 0;
	check_list->SO = 0;
	check_list->EA = 0;
	return (check_list);
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
	if (check_list->F > 1 || check_list->C > 1
		|| check_list->NO > 1 || check_list->WE > 1
		|| check_list->SO > 1 || check_list->EA > 1)
		return (true);
	return (false);
}

bool	is_not_elements(t_check_bb *check_list)
{
	if (check_list->F != 1 || check_list->C != 1
		|| check_list->NO != 1 || check_list->WE != 1
		|| check_list->SO != 1 || check_list->EA != 1)
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
	if (is_not_elements(check_list))
	{
		free(line);
		free(check_list);
		printf("Error\nSet elements.\n");
		return (false);
	}
	return (true);
}
