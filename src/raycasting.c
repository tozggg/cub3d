/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:21:17 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 02:09:01 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	cal_color(t_dda *dda, t_game *game, int x)
{
	if (dda->side == 0 || dda->side == 1)
		dda->wallX = game->pos_y + dda->perpwallDist * dda->rayDir_y;
	else
		dda->wallX = game->pos_x + dda->perpwallDist * dda->rayDir_x;
	dda->wallX -= floor(dda->wallX);
	dda->tex_x = (int)(dda->wallX * (double)TEX_SIZE);
	if (dda->side == 0 && dda->rayDir_x > 0)
		dda->tex_x = TEX_SIZE - dda->tex_x - 1;
	if (dda->side == 1 && dda->rayDir_y < 0)
		dda->tex_x = TEX_SIZE - dda->tex_x - 1;
	dda->step = TEX_SIZE * 1.0 / dda->lineheight;
	dda->texPos = (dda->drawstart - HEIGHT / 2 + dda->lineheight / 2) * dda->step;
	dda->index_y = dda->drawstart;
	while (dda->index_y < dda->drawend)
	{
		dda->tex_y = (int)dda->texPos & (TEX_SIZE - 1);
		dda->texPos += dda->step;
		game->buf[dda->index_y][x] = \
				game->texture[dda->texnum][TEX_SIZE * dda->tex_x + dda->tex_y];
		++dda->index_y;
	}
}

static void	tex_input(t_dda *dda, t_game *game)
{
	if (dda->side == 0 || dda->side == 1)
		dda->perpwallDist = (dda->map_x - game->pos_x + (1 - dda->step_x) / 2) / dda->rayDir_x;
	else
		dda->perpwallDist = (dda->map_y - game->pos_y + (1 - dda->step_y) / 2) / dda->rayDir_y;
	dda->lineheight = (int)((HEIGHT) / dda->perpwallDist);
	dda->drawstart = HEIGHT / 2 - dda->lineheight / 2;
	if (dda->drawstart < 0)
		dda->drawstart = 0; // target이 근접했을때 window 밖으로 target이 넘어가 시야 밖으로 갈때 처리
	dda->drawend = HEIGHT / 2 + dda->lineheight / 2;
	if (dda->drawend >= HEIGHT)
		dda->drawend = HEIGHT - 1;
	if (game->map[dda->map_y][dda->map_x] == '1' && dda->side == 0)
		dda->texnum = WE; // 왼
	else if (game->map[dda->map_y][dda->map_x] == '1' && dda->side == 1)
		dda->texnum = EA; // 오
	else if (game->map[dda->map_y][dda->map_x] == '1' && dda->side == 2)
		dda->texnum = NO; // 아래
	else if (game->map[dda->map_y][dda->map_x] == '1' && dda->side == 3)
		dda->texnum = SO; // 위
}

static void	hit_check(t_dda *dda, t_game *game)
{
	while (dda->hit == 0)
	{
		if (dda->sideDist_x < dda->sideDist_y)
		{
			dda->sideDist_x += dda->deltaDist_x;
			dda->map_x += dda->step_x;
			if (dda->step_x == 1)
				dda->side = 0;
			else if (dda->step_x == -1)
				dda->side = 1; // 오른쪽
		}
		else
		{
			dda->sideDist_y += dda->deltaDist_y;
			dda->map_y += dda->step_y;
			if (dda->step_y == 1)
				dda->side = 2; // 아래
			else if (dda->step_y == -1)
				dda->side = 3; // 위
		}
		if (game->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}

static void	cal_sideDist(t_dda *dda, t_game *game)
{
	if (dda->rayDir_x < 0)
	{
		dda->step_x = -1;
		dda->sideDist_x = (game->pos_x - dda->map_x) * dda->deltaDist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sideDist_x = (dda->map_x + 1.0 - game->pos_x) * dda->deltaDist_x;
	}
	if (dda->rayDir_y < 0)
	{
		dda->step_y = -1;
		dda->sideDist_y = (game->pos_y - dda->map_y) * dda->deltaDist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sideDist_y = (dda->map_y + 1.0 - game->pos_y) * dda->deltaDist_y;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	t_dda	dda;

	x = -1;
	while (++x < WIDTH)
	{
		dda.camera_x = 2 * x / (double)WIDTH - 1;
		dda.rayDir_x = game->dir_x + game->plane_x * dda.camera_x;
		dda.rayDir_y = game->dir_y + game->plane_y * dda.camera_x;
		dda.map_x = (int)game->pos_x;
		dda.map_y = (int)game->pos_y;
		dda.deltaDist_x = fabs(1 / dda.rayDir_x);
		dda.deltaDist_y = fabs(1 / dda.rayDir_y);
		dda.hit = 0;
		cal_sideDist(&dda, game);
		hit_check(&dda, game);
		tex_input(&dda, game);
		cal_color(&dda, game, x);
	}
}
