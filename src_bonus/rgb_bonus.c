/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:36:05 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/21 19:29:22 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	rgb_comma_check(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			++cnt;
		++i;
	}
	if (cnt == 2)
		return (0);
	return (1);
}

static int	rgb_check(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (1);
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	rgb_atoi(char **split, int *r, int *g, int *b)
{
	int	res;
	int	cnt;
	int	i;

	cnt = 0;
	res = 0;
	while (split[cnt])
	{
		i = -1;
		res = 0;
		while (split[cnt][++i])
		{
			res = 10 * res + (split[cnt][i] - '0');
			if (res < 0 || res > 255)
				return (1);
			if (!split[cnt][i + 1] && cnt == 0)
				*r = res;
			else if (!split[cnt][i + 1] && cnt == 1)
				*g = res;
			else if (!split[cnt][i + 1] && cnt == 2)
				*b = res;
		}
		cnt++;
	}
	return (0);
}

int	get_rgb(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	int		i;

	if (rgb_comma_check(str))
		error_out("Error\ncannot load RGB color");
	split = ft_split(str, ',');
	if (!split)
		error_out("Error\nsplit error");
	if (rgb_check(split))
		error_out("Error\ncannot load RGB color");
	if (rgb_atoi(split, &r, &g, &b))
		error_out("Error\ncannot load RGB color");
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return ((r * 256 * 256) + (g * 256) + b);
}
