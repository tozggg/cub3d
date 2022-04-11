/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:49:34 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:39:20 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	loop(t_game *game)
{
	background(game);
	raycasting(game);
	display(game);
	update_game(game);
	return (0);
}

int main(int ac, char *av[])
{
	t_file	file;
	t_game	game;

	if (ac != 2 || !is_cub_extension(av[1]))
		error_out("Error\nusage: ./cub3d [map.cub]");
	check_file(&file, av[1]);
	make_game(&game, file);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win, X_EVENT_MOUSE_MOVE, 0, &mouse_move, &game);
	mlx_loop_hook(game.mlx, &loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
