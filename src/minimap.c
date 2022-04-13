/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:58:31 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 17:27:49 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	background_buf_select(t_game *game, int x, int y)
{
	double	rad;
	int		mx;
	int		my;

	rad = pow(abs(x - 79), 2) + pow(abs(y - 79), 2);
	if (rad > 6400)
		return ;
	mx = (int)(game->pos_x - (79 - x) / 16.0);
	my = (int)(game->pos_y - (79 - y) / 16.0);
	if (mx < 0 || mx >= game->map_w || my < 0 || my >= game->map_h || \
		game->map[my][mx] == ' ')
		game->buf[y][x] = 0x677a78;
	else if (game->map[my][mx] == '1')
		game->buf[y][x] = 0x1d1b1e;
	else
		game->buf[y][x] = 0xccccca;
}

static void	minimap_background(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 160)
	{
		x = -1;
		while (++x < 160)
			background_buf_select(game, x, y);
	}	
}

static void	character_buf_select(t_game *game, int x, int y, double basis)
{
	double	rad;
	double	angle;

	rad = pow(abs(x - 79), 2) + pow(abs(y - 79), 2);
	if (rad > 6400)
		return ;
	if (rad >= 6084)
	{
		game->buf[y][x] = 0x2F4F4F;
		return ;
	}
	angle = acos((game->dir_x * (x - 79) + game->dir_y * (y - 79)) \
							/ (sqrt(pow(x - 79, 2) + pow(y - 79, 2))));
	if (basis * -1 <= angle && angle <= basis)
		game->buf[y][x] += 0xCC0000;
	if (rad < 64)
		game->buf[y][x] = 0xFFD400;
}

static void	minimap_character(t_game *game)
{
	int		x;
	int		y;
	double	basis;

	basis = 33.4 * (M_PI / 180);
	y = -1;
	while (++y < 160)
	{
		x = -1;
		while (++x < 160)
			character_buf_select(game, x, y, basis);
	}	
}

void	minimap(t_game *game)
{
	minimap_background(game);
	minimap_character(game);
}
