/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:22:50 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:31:13 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_left(t_game *game)
{
	double	x;
	double	y;
	double	p_x;
	double	p_y;

	x = game->dir_x;
	y = game->dir_y;
	p_x = game->plane_x;
	p_y = game->plane_y;
	game->dir_x = x * cos(game->rotspeed) - y * sin(game->rotspeed);
	game->dir_y = x * sin(game->rotspeed) + y * cos(game->rotspeed);
	game->plane_x = p_x * cos(game->rotspeed) - p_y * sin(game->rotspeed);
	game->plane_y = p_x * sin(game->rotspeed) + p_y * cos(game->rotspeed);
}

void	rotate_right(t_game *game)
{
	double	x;
	double	y;
	double	p_x;
	double	p_y;

	x = game->dir_x;
	y = game->dir_y;
	p_x = game->plane_x;
	p_y = game->plane_y;
	game->dir_x = x * cos(-(game->rotspeed)) - y * sin(-(game->rotspeed));
	game->dir_y = x * sin(-(game->rotspeed)) + y * cos(-(game->rotspeed));
	game->plane_x = p_x * cos(-(game->rotspeed)) - p_y * sin(-(game->rotspeed));
	game->plane_y = p_x * sin(-(game->rotspeed)) + p_y * cos(-(game->rotspeed));
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		game->key.w = 1;
	else if (keycode == KEY_A)
		game->key.a = 1;
	else if (keycode == KEY_S)
		game->key.s = 1;
	else if (keycode == KEY_D)
		game->key.d = 1;
	else if (keycode == KEY_LEFT)
		game->key.left = 1;
	else if (keycode == KEY_RIGHT)
		game->key.right = 1;
	else if (keycode == MOUSE_ON && game->key.mouse_on == 0)
	{
		game->key.mouse_on = 1;
		mlx_mouse_show();
	}
	else if (keycode == MOUSE_ON && game->key.mouse_on == 1)
	{
		game->key.mouse_on = 0;
		mlx_mouse_hide();
	}
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key.w = 0;
	else if (keycode == KEY_A)
		game->key.a = 0;
	else if (keycode == KEY_S)
		game->key.s = 0;
	else if (keycode == KEY_D)
		game->key.d = 0;
	else if (keycode == KEY_LEFT)
		game->key.left = 0;
	else if (keycode == KEY_RIGHT)
		game->key.right = 0;
	return (0);
}
