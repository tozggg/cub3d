/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:19:44 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/13 16:00:13 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	check_info(t_file *file)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (file->split[i] == NULL)
			error_out("Error\ninvalid file");
		if (ft_strncmp(file->split[i], "NO ", 3) == 0)
			file->info[NO] = file->split[i];
		else if (ft_strncmp(file->split[i], "SO ", 3) == 0)
			file->info[SO] = file->split[i];
		else if (ft_strncmp(file->split[i], "WE ", 3) == 0)
			file->info[WE] = file->split[i];
		else if (ft_strncmp(file->split[i], "EA ", 3) == 0)
			file->info[EA] = file->split[i];
		else if (ft_strncmp(file->split[i], "F ", 2) == 0)
			file->info[F] = file->split[i];
		else if (ft_strncmp(file->split[i], "C ", 2) == 0)
			file->info[C] = file->split[i];
	}
	while (--i >= 0)
	{
		if (!file->info[i])
			error_out("Error\ninvalid file");
	}
}

void	check_file(t_file *file, char *path)
{
	char	*str;

	init_file(file);
	str = read_file(path);
	file->split = ft_split(str, '\n');
	free(str);
	if (!file->split)
		error_out("Error\nsplit error");
	check_info(file);
	check_map(file);
	if (!file->c_flag)
		error_out("Error\ninvalid map");
}
