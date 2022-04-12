/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:58:31 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 02:51:56 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	minimap_background(t_game *game)
{
	int		mx;
	int		my;
	int		x;
	int		y;
	double	rad;

	y = -1;
	while (++y < 160)
	{
		x = -1;
		while (++x < 160)
		{
			rad = pow(abs(x - 80), 2) + pow(abs(y - 80), 2);
			if (rad > 6400)
				continue ;
			mx = (int)(game->pos_x - (80 - (double)x) / 16);
			my = (int)(game->pos_y - (80 - (double)y) / 16);
			if (mx < 0 || mx >= game->map_w || my < 0 || my >= game->map_h || \
				game->map[my][mx] == ' ')
				game->buf[y][x] = 0x677a78;
			else if (game->map[my][mx] == '1')
				game->buf[y][x] = 0x1d1b1e;
			else
				game->buf[y][x] = 0xccccca;
		}
	}	
}

static void	minimap_character(t_game *game)
{
	int		x;
	int		y;
	double	rad;
	double	basis;
	double	angle;

	basis = 33.4 * (M_PI / 180);
	y = -1;
	while (++y < 160)
	{
		x = -1;
		while (++x < 160)
		{
			rad = pow(abs(x - 80), 2) + pow(abs(y - 80), 2);
			if (rad > 6400)
				continue ;
			if (6241 <= rad && rad <= 6400)
			{
				game->buf[y][x] = 0;
				continue ;
			}
			angle = acos((game->dir_x * (x - 80) + game->dir_y * (y - 80)) \
							/ (sqrt(pow(x - 80, 2) + pow(y - 80, 2))));
			if (basis * -1 <= angle && angle <= basis)
				game->buf[y][x] += 0xCC0000;
			if (rad < 64)
				game->buf[y][x] = 0xFF0000;
		}
	}	
}

void	minimap(t_game *game)
{
	minimap_background(game);
	minimap_character(game);
}
