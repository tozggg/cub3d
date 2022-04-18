/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:13:50 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:28:47 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_out(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

int	is_cub_extension(char *str)
{
	if (ft_strlen(str) < 4)
		return (0);
	while (*str)
		++str;
	str -= 4;
	if (ft_strncmp(str, ".cub", 4) == 0)
		return (1);
	return (0);
}

char	*read_file(char *pathname)
{
	char	*res;
	char	*buf;
	int		fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		error_out("Error\nFailed to open file");
	res = (char *)malloc(sizeof(char));
	buf = (char *)malloc(sizeof(char) * 2);
	if (!res || !buf)
		error_out("Error\nmalloc error");
	res[0] = 0;
	while (read(fd, buf, 1))
	{
		buf[1] = 0;
		res = ft_strjoin_free_s1(res, buf);
		if (!res)
			error_out("Error\nstrjoin error");
	}
	free(buf);
	close(fd);
	return (res);
}

char	*cut_path(char *str, char *cut)
{
	while (*cut && *str)
	{
		if (*cut != *str)
			return (NULL);
		++cut;
		++str;
	}
	while (*str == ' ')
		++str;
	return (str);
}

int	rgb_atoi(char **split, int *r, int *g, int *b)
{
	int	res;
	int	i;
	int	cnt;

	cnt = 0;
	res = 0;
	while (split[cnt])
	{
		i = -1;
		res = 0;
		while (ft_isdigit(split[cnt][++i]))
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
