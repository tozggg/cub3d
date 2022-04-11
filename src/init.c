/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:18:20 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:34:21 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_file(t_file *file)
{
	int i;

	file->split = NULL;
	i = 0;
	while (i < 6)
		file->info[i++] = NULL;
	file->map = NULL;
	file->map_w = 0;
	file->map_h = 0;
	file->c_flag = 0;
}

static int	**init_buf(void)
{
	int	**res;
	int	*tmp;
	int	i;

	res = (int **)malloc(sizeof(int *) * HEIGHT);
	if (!res)
		error_out("Error\nmalloc error");
	i = 0;
	while (i < HEIGHT)
	{
		tmp = (int *)ft_calloc(WIDTH, sizeof(int));
		if (!tmp)
			error_out("Error\nmalloc error");
		res[i] = tmp;
		++i;
	}
	return (res);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->key.w = 0;
	game->key.s = 0;
	game->key.a = 0;
	game->key.d = 0;
	game->key.left = 0;
	game->key.right = 0;
	game->key.mouse_on = 0;
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, \
										&game->img.size_l, &game->img.endian);
	game->buf = init_buf();
	game->movespeed = 0.04;
	game->rotspeed = 0.04;
}
