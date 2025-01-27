/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:03 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:03 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdbool.h>

# define PLAYER_ANGLE_SPEED 20
# define PLAYER_MOVE_SPEED 0.3
# define FOV 90 //視野角
# define X_SIZE 1600
# define Y_SIZE 900
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 65363
# define KEY_L 65361
# define KEY_ESC 65307
# define MOD_NORTH 0
# define MOD_EAST 1
# define MOD_SOUTH 2
# define MOD_WEST 3
# define OBJECT 1
# define EMPTY 2
# define TALL 0.5

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_vector
{
	double	direction_x;
	double	direction_y;
	double	direction_z;
}	t_vector;

typedef struct s_man
{
	double		pos_x;
	double		pos_y;
	double		pos_z;
	double		angle_v;
	double		angle_h;
	double		htan;
	double		vtan;
	double		hsin;
	double		hcos;
	double		vsin;
	t_vector	vect;
}	t_man;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	int		**map;
	int		frame_height;
	int		frame_width;
	int		mapwidth;
	int		mapheight;
	double	fov;
	double	const_fov;
	t_man	man;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	img;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_cub3d;

typedef struct s_check_bb
{
	int	f;
	int	c;
	int	no;
	int	we;
	int	so;
	int	ea;
}	t_check_bb;

typedef struct s_map_bb
{
	int		v_len;
	int		h_len;
	char	**map;
}	t_map_bb;

int			isargcerror(int ac);
int			isfilenameerror(char **av);
int			isfileopenerror(char **av);
int			keymove(int keycode, t_cub3d *viw);
void		cub3d(t_cub3d *viw, char *path);
void		push_w(t_cub3d *viw);
void		push_a(t_cub3d *viw);
void		push_s(t_cub3d *viw);
void		push_d(t_cub3d *viw);
void		push_r(t_cub3d *viw);
void		push_l(t_cub3d *viw);
void		push_esc(t_cub3d *viw);
void		init_fromfile(t_cub3d *viw, char *path);
void		initialimg(t_cub3d *viw, char *path);
void		check_rgb(char *str);
void		format_gnl(char *str);
int			get_pixel_color(t_img *img, int x, int y);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			monitor_pixelcolor(t_cub3d *viw, int x, int y);
int			g_color(t_cub3d *viw, t_man ray);
int			g_color_s_w(t_cub3d *viw, t_man ray);
int			g_color_w_s(t_cub3d *viw, t_man ray);
int			g_color_w_n(t_cub3d *viw, t_man ray);
int			g_color_n_w(t_cub3d *viw, t_man ray);
int			y_img(t_cub3d *viw, t_man ray, int tmp, int *color);
int			x_img(t_cub3d *viw, t_man ray, int tmp, int *color);
void		d_tuning(t_man *ray, int flag);
void		first_img(t_cub3d *viw);
double		ftoradian(double angle);
double		util_n_e(t_man ray, int n);
double		util_e_n(t_man ray, int n);
double		util_e_s(t_man ray, int n);
double		util_s_e(t_man ray, int n);
double		util_s_w(t_man ray, int n);
double		util_w_s(t_man ray, int n);
double		util_w_n(t_man ray, int n);
double		util_n_w(t_man ray, int n);
int			mapcreated(t_cub3d *viw, char *str);
int			create_map(t_cub3d *viw, char *str);
int			mapsetbyte(t_cub3d *viw, char *str, int n, int *k);
int			countmap(t_cub3d *viw, char *fdr);
char		*skip(int fd);
void		display_cub3d_contents(t_cub3d *viw);
int			set_manpos(t_cub3d *viw);
int			top(t_cub3d *viw);
int			bot(t_cub3d *viw);
int			left(t_cub3d *viw);
int			right(t_cub3d *viw);
int			ue(t_cub3d *viw, int x, int y);
int			hidari(t_cub3d *viw, int x, int y);
int			migi(t_cub3d *viw, int x, int y);
int			shita(t_cub3d *viw, int x, int y);
int			mapcheck(t_cub3d *viw);
int			mapch(t_cub3d *viw);
int			ch(t_cub3d *viw, int x, int y);
void		lastft(int *n, int *len, char **str, int *fd);
//bb
bool		test_bb(int ac, char **av);
bool		name_check(char *name);
bool		open_check(char *file_path);
bool		check_color(char *line, t_check_bb *check_list, int fd);
bool		is_correct_list(t_check_bb *check_list, char *line);
t_check_bb	*init_check_list(void);
void		check_list_update(char *line, t_check_bb **check_list);
int			get_map_v_len(char *file_path);
bool		is_map(char *line);
void		free_box(char **box);
void		get_map(char *path, t_map_bb *map_list);
void		bb_create_map(t_map_bb *map_list, char *file_path);
bool		check_map(t_map_bb *map_list);
bool		is_s1(char c);
bool		is_around_s1(char **map, int i, int j);
#endif
