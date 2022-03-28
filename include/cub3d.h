/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:21:54 by jeson             #+#    #+#             */
/*   Updated: 2022/03/28 12:45:38 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include <unistd.h>
// # include <stdlib.h>
// # include <fcntl.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define IMG_SIZE 64

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
// # define KEY_RIGHT
// # define KEY_LEFT

# define FALSE 0
# define TRUE 1

typedef struct s_map
{
	int	b_x;
	int	b_y;
}	t_map;

typedef struct s_obj
{
	int	o_x;
	int	o_y;
}	t_obj;

typedef struct s_state
{
	int	playing;
	// int	moving;
	int	mv_x;
	int	mv_y;
}	t_state;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall[4];
	int		c_x;
	int		c_y;
	int		c_z;
	t_obj	*wall;
	t_obj	*item;
	t_state	state;
}	t_game;

#endif
