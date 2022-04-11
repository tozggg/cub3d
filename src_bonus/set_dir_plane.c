/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:20:12 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:20:22 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_dir_plane_n(t_game *game)
{
	game->dir_x = 0;
	game->dir_y = 1;
	game->plane_x = 0.66;
	game->plane_y = 0;
}

void	set_dir_plane_s(t_game *game)
{
	game->dir_x = 0;
	game->dir_y = -1;
	game->plane_x = -0.66;
	game->plane_y = 0;
}

void	set_dir_plane_w(t_game *game)
{
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
}

void	set_dir_plane_e(t_game *game)
{
	game->dir_x = 1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = -0.66;
}
