/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:38:02 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/12 19:38:02 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rgb(t_rgb *st, char *str)
{
	check_rgb(str);
	st->red = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	st->green = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	st->blue = ft_atoi(str);
}

void	set_viw(t_cub3d *viw, char *str)
{
	format_gnl(str);
	if (!ft_strcmp("\n", str))
		return ;
	if (!ft_strncmp("NO ", str, 3))
		viw->north.path = ft_strdup(str + 3);
	else if (!ft_strncmp("SO ", str, 3))
		viw->south.path = ft_strdup(str + 3);
	else if (!ft_strncmp("WE ", str, 3))
		viw->west.path = ft_strdup(str + 3);
	else if (!ft_strncmp("EA ", str, 3))
		viw->east.path = ft_strdup(str + 3);
	else if (!ft_strncmp("F ", str, 2))
		set_rgb(&viw->floor, str + 2);
	else if (!ft_strncmp("C ", str, 2))
		set_rgb(&viw->ceiling, str + 2);
}

int	is_xpm(char *str)
{
	int	l;
	int	file;

	l = ft_strlen(str);
	if (ft_strcmp(str + l - 4, ".xpm"))
		return (0);
	file = open(str, O_RDONLY);
	if (file == -1)
		return (0);
	close(file);
	return (1);
}

void	init_fromfile(t_cub3d *viw, char *path)
{
	int		file;
	char	*str;

	file = open(path, O_RDONLY);
	str = get_next_line(file);
	while (str)
	{
		set_viw(viw, str);
		free(str);
		str = get_next_line(file);
	}
	if (str)
		free(str);
	close(file);
	if (!is_xpm(viw->north.path) || !is_xpm(viw->south.path)
		|| !is_xpm(viw->east.path) || !is_xpm(viw->west.path))
	{
		printf("Error: worng img filepath\n");
		exit(1);
	}
}

void	initialimg(t_cub3d *viw, char *path)
{
	init_fromfile(viw, path);
	viw->north.img = mlx_xpm_file_to_image(viw->mlx,
			viw->south.path, &viw->north.width, &viw->north.height);
	viw->north.addr = mlx_get_data_addr(viw->north.img,
			&viw->north.bits_per_pixel, &viw->north.line_length,
			&viw->north.endian);
	viw->south.img = mlx_xpm_file_to_image(viw->mlx,
			viw->north.path, &viw->south.width, &viw->south.height);
	viw->south.addr = mlx_get_data_addr(viw->south.img,
			&viw->south.bits_per_pixel, &viw->south.line_length,
			&viw->south.endian);
	viw->east.img = mlx_xpm_file_to_image(viw->mlx,
			viw->west.path, &viw->east.width, &viw->east.height);
	viw->east.addr = mlx_get_data_addr(viw->east.img,
			&viw->east.bits_per_pixel, &viw->east.line_length,
			&viw->east.endian);
	viw->west.img = mlx_xpm_file_to_image(viw->mlx,
			viw->east.path, &viw->west.width, &viw->west.height);
	viw->west.addr = mlx_get_data_addr(viw->west.img,
			&viw->west.bits_per_pixel, &viw->west.line_length,
			&viw->west.endian);
}
