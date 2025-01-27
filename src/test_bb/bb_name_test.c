/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_name_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 05:40:35 by tobaba            #+#    #+#             */
/*   Updated: 2025-01-27 05:40:35 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

bool	name_check(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (name[len - 4] != '.' || name[len - 3] != 'c'
		|| name[len - 2] != 'u' || name[len - 1] != 'b')
	{
		printf("Error\nFile name is not correct. (***.cub)\n");
		return (true);
	}
	return (false);
}

bool	open_check(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCant open this file.\n");
		return (true);
	}
	close(fd);
	return (false);
}
