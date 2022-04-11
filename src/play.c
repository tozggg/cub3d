/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:26:15 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:26:52 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	background(t_game *game)
{
	int x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				game->buf[y][x] = game->ceiling;
			else
				game->buf[y][x] = game->floor;
		}
	}
}

void	display(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			game->img.data[y * WIDTH + x] = game->buf[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	update_game(t_game *game)
{
	if (game->key.w)
		move_front(game);
	if (game->key.a)
		move_left(game);
	if (game->key.s)
		move_back(game);
	if (game->key.d)
		move_right(game);
	if (game->key.left)
		rotate_left(game);
	if (game->key.right)
		rotate_right(game);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	x_prev;
	int			v;

	if (game->key.mouse_on == 1)
		return (0);
	v = x - x_prev;
	x_prev = x;
	if (v < 0)
		rotate_left(game);
	if (v > 0)
		rotate_right(game);
	if (x > WIDTH - 1 || x < 0)
	{
		mlx_mouse_move(game->win, WIDTH / 2, HEIGHT / 2);
		x_prev = WIDTH / 2;
	}
	return (0);
}
