/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:50:22 by jeson             #+#    #+#             */
/*   Updated: 2022/03/28 12:51:02 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	closing_game(t_game *game)
// {
// 	mlx_destroy_window(game->mlx, game->win);
// 	exit(0);
// }

// int	key_press(int keycode, t_game *game)
// {
// 	if (keycode == KEY_ESC)
// 		closing_game(game);
// 	if (keycode == KEY_W)
// 		command(game, game->x, game->y - 1, UP);
// 	if (keycode == KEY_A)
// 		command(game, game->x - 1, game->y, LEFT);
// 	if (keycode == KEY_S)
// 		command(game, game->x, game->y + 1, DOWN);
// 	if (keycode == KEY_D)
// 		command(game, game->x + 1, game->y, RIGHT);
// 	return (0);
// }

// int	loop(t_game *game)
// {
// 	if (game->state.playing == FALSE)
// 		return (0);
// 	if (game->state.moving == FALSE)
// 		standing(game);
// 	else
// 	{
// 		if (game->state.move_place == MOVE_TO_TILE)
// 			move_to_tile(game);
// 		else if (game->state.move_place == MOVE_TO_HONEY)
// 			move_to_honey(game);
// 		else if (game->state.move_place == MOVE_TO_EXIT)
// 			move_to_exit(game);
// 	}
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	t_game	game;
// 	char	*map;

// 	if (argc != 2)
// 		error_exit("Invalid Maps !\n");
// 	map = read_file(argv[1]);
// 	check_map(map);
// 	init_game(&game);
// 	mapping_game(&game, map);
// 	free(map);
// 	display_window(&game);
// 	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &closing_game, &game);
// 	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
// 	mlx_loop_hook(game.mlx, &loop, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }
