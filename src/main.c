/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:08 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:08 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//マップファイルの取り込み
//レイがマップ外に行った時の処理(セグフォになる)
//ウィンドウサイズ変更時のハンドル

int	isargumentserror(int ac, char **av)
{
	if (isargcerror(ac) || isfilenameerror(av) || isfileopenerror(av))
		return (1);
	return (0);
}

void	format_gnl(char *str)
{
	while (*str)
		str++;
	if (*(str - 1) == '\n')
		*(str - 1) = '\0';
}

int	first_img_sub(void *param)
{
	t_cub3d	*viw;

	viw = (t_cub3d *)param;
	first_img(viw);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub3d		viw;

	viw.frame_height = Y_SIZE;
	viw.frame_width = X_SIZE;
	viw.man.pos_z = 0.5;
	viw.fov = FOV;
	viw.const_fov = (double)viw.fov / 1920 * 1080;
	if (test_bb(ac, av) || isargumentserror(ac, av))
		return (1);
	if (create_map(&viw, *(av + 1)))
		exit(0);
	if (set_manpos(&viw))
	{
		printf("Error: Player info is wrong.\n");
		exit(0);
	}
	viw.mlx = mlx_init();
	viw.win = mlx_new_window(viw.mlx, X_SIZE, Y_SIZE, "cub3D");
	viw.img.img = mlx_new_image(viw.mlx, X_SIZE, Y_SIZE);
	viw.img.addr = mlx_get_data_addr(viw.img.img, &viw.img.bits_per_pixel,
			&viw.img.line_length, &viw.img.endian);
	cub3d(&viw, *(av + 1));
	mlx_loop_hook(viw.mlx, first_img_sub, (void *)&viw);
	mlx_loop(viw.mlx);
	exit(0);
}
