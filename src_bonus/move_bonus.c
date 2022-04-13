/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:21:44 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 16:14:38 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	move_front(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x + (game->dir_x * game->movespeed);
	move_y = game->pos_y + (game->dir_y * game->movespeed);
	if (game->map[(int)move_y][(int)game->pos_x] != '1')
		game->pos_y = move_y;
	if (game->map[(int)game->pos_y][(int)move_x] != '1')
		game->pos_x = move_x;
}

void	move_back(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x - (game->dir_x * game->movespeed);
	move_y = game->pos_y - (game->dir_y * game->movespeed);
	if (game->map[(int)move_y][(int)game->pos_x] != '1')
		game->pos_y = move_y;
	if (game->map[(int)game->pos_y][(int)move_x] != '1')
		game->pos_x = move_x;
}

void	move_left(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x - (game->plane_x * game->movespeed);
	move_y = game->pos_y - (game->plane_y * game->movespeed);
	if (game->map[(int)move_y][(int)game->pos_x] != '1')
		game->pos_y = move_y;
	if (game->map[(int)game->pos_y][(int)move_x] != '1')
		game->pos_x = move_x;
}

void	move_right(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x + (game->plane_x * game->movespeed);
	move_y = game->pos_y + (game->plane_y * game->movespeed);
	if (game->map[(int)move_y][(int)game->pos_x] != '1')
		game->pos_y = move_y;
	if (game->map[(int)game->pos_y][(int)move_x] != '1')
		game->pos_x = move_x;
}
