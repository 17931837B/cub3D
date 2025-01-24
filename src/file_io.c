/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:10:51 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/16 00:10:51 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	nfp(char *str, int *flag)
{
	if (!ft_strncmp(str, "NO ", 3))
		flag[0] = 1;
	else if (!ft_strncmp(str, "SO ", 3))
		flag[1] = 1;
	else if (!ft_strncmp(str, "WE ", 3))
		flag[2] = 1;
	else if (!ft_strncmp(str, "EA ", 3))
		flag[3] = 1;
	else if (!ft_strncmp(str, "F ", 2))
		flag[4] = 1;
	else if (!ft_strncmp(str, "C ", 2))
		flag[5] = 1;
	else if (ft_strcmp("\n", str))
		return (1);
	return (0);
}

void	notfilepath(char *str, int *flag)
{
	int		fd;
	char	*gnl;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (nfp(gnl, flag))
			break ;
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (gnl)
		free(gnl);
	close(fd);
}

int	isnotfilepath(char *str)
{
	int		flag[6];
	int		n;

	n = 0;
	while (n < 6)
	{
		flag[n] = 0;
		n++;
	}
	notfilepath(str, flag);
	n = 0;
	while (n < 6)
	{
		if (!flag[n])
			return (1);
		n++;
	}
	return (0);
}

int	isfileerror(char *str)
{
	if (isnotfilepath(str))
	{
		printf("Error: Need file path for NO SO WE EA F C.\n");
		return (1);
	}
	return (0);
}

int	create_map(t_cub3d *viw, char *str)
{
	if (isfileerror(str))
		return (1);
	if (mapcreated(viw, str))
	{
		printf("Error: Map cant create.\n");
		return (1);
	}
	if (mapcheck(viw))
	{
		printf("Error: Map is wrong.\n");
		return (1);
	}
	return (0);
}
