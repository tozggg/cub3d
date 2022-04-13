/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:16:07 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 16:04:28 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>

# define HEIGHT 640
# define WIDTH 960
# define TEX_SIZE 128

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define X_EVENT_MOUSE_MOVE 6

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define MOUSE_ON 35

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef struct s_file
{
	char	**split;
	char	*info[6];
	char	**map;
	int		map_w;
	int		map_h;
	int		c_x;
	int		c_y;
	char	c_flag;
}	t_file;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		mouse_on;
}	t_key;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_key	key;
	t_img	img;
	int		**buf;
	int		*texture[4];
	int		ceiling;
	int		floor;
	char	**map;
	int		map_w;
	int		map_h;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotspeed;
}	t_game;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		tex_x;
	int		tex_y;
	int		index_y;
	double	wallx;
	double	step;
	double	texpos;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
}	t_dda;

// utils.c
void	error_out(char *msg);
int		is_cub_extension(char *str);
char	*read_file(char *pathname);
char	*cut_path(char *str, char *cut);
int		cut_rgb(char *str);

// init.c
void	init_file(t_file *file);
void	init_game(t_game *game);

// check_map.c
void	check_map(t_file *file);

// check.c
void	check_info(t_file *file);
void	check_file(t_file *file, char *path);

// set_dir_plane.c
void	set_dir_plane_n(t_game *game);
void	set_dir_plane_s(t_game *game);
void	set_dir_plane_w(t_game *game);
void	set_dir_plane_e(t_game *game);

// parse.c
void	make_game(t_game *game, t_file file);

// raycating.c
void	raycasting(t_game *game);

// move.c
void	move_front(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// key.c
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

// minimap.c
void	minimap(t_game *game);

// play.c
void	background(t_game *game);
void	display(t_game *game);
void	update_game(t_game *game);
int		mouse_move(int x, int y, t_game *game);

// main.c
int		close_game(t_game *game);

#endif
