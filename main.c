/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:49:34 by taejkim           #+#    #+#             */
/*   Updated: 2022/03/31 16:00:11 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>


#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5


typedef struct s_file
{
	char	*str;
	char	**split;
	char	*info[6];
	char	**map;
	int		map_w;
	int		map_h;
	int		c_flag;
}	t_file;

typedef struct s_game
{
}	t_game;


// libft //////////////////////////////////////////////////////////
int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		ptr[i++] = s1[j];
	j = -1;
	while (s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = 0;
	free(s1);
	return (ptr);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s1_u;
	const unsigned char *s2_u;
	size_t				i;

	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	i = 0;
	while (s1_u[i] && s2_u[i] && (i < n))
	{
		if (s1_u[i] != s2_u[i])
			return (s1_u[i] - s2_u[i]);
		++i;
	}
	if (i == n)
		return (0);
	if (s1_u[i] != s2_u[i])
		return (s1_u[i] - s2_u[i]);
	else
		return (0);
}

static int	get_size(char const *s, char c)
{
	int res;
	int check;
	int i;

	res = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (check == 0)
				++res;
			check = 1;
		}
		else
			check = 0;
		++i;
	}
	return (res);
}

static char	*get_ptr_child(char const *s, char c, int i)
{
	char	*res;
	int		start;
	int		end;
	int		j;

	start = i;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		++i;
	}
	end = i;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (start < end)
		res[j++] = s[start++];
	res[j] = 0;
	return (res);
}

static void	get_ptr(char **ptr, char const *s, char c)
{
	int index;
	int check;
	int i;

	index = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (check == 0)
				ptr[index++] = get_ptr_child(s, c, i);
			check = 1;
		}
		else
			check = 0;
		++i;
	}
	ptr[index] = 0;
}

static void	free_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		++i;
	}
	free(ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = get_size(s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	get_ptr(ptr, s, c);
	i = 0;
	while (i < size)
	{
		if (ptr[i] == NULL)
		{
			free_ptr(ptr);
			return (NULL);
		}
		++i;
	}
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		++i;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
///////////////////////////////////////////////////////////////////

//utils
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
	return (res);
}

//init
void	init_file(t_file *file)
{
	int i;

	file->str = NULL;
	file->split = NULL;
	i = 0;
	while (i < 6)
		file->info[i++] = NULL;
	file->map = NULL;
	file->map_w = 0;
	file->map_h = 0;
	file->c_flag = 0;
}

//check
void	check_info(t_file *file)
{
	int i;

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

void	scan_map(t_file *file)
{
	int	i;
	int	j;

	i = 6;
	if (!file->split[i])
		error_out("Error\ninvalid map");
	while (file->split[i])
	{
		j = 0;
		while (file->split[i][j])
			++j;
		if (file->map_w < j)
			file->map_w = j;
		++file->map_h;
		++i;
	}
}

void	append_map(t_file *file)
{
	int	i;
	int	j;

	file->map = (char **)malloc(sizeof(char *) * (file->map_h + 3));
	i = 0;
	file->map[i] = ft_calloc(file->map_w + 3, sizeof(char));
	ft_memset(file->map[i++], ' ', file->map_w + 2);
	while (i <= file->map_h)
	{
		file->map[i] = ft_calloc(file->map_w + 3, sizeof(char));
		j = 0;
		file->map[i][j++] = ' ';
		while (file->split[i + 5][j - 1])
		{
			file->map[i][j] = file->split[i + 5][j - 1];
			j++;
		}
		while (j <= file->map_w + 1)
			file->map[i][j++] = ' ';
		file->map[i][j] = 0;
		++i;
	}
	file->map[i] = ft_calloc(file->map_w + 3, sizeof(char));
	ft_memset(file->map[i++], ' ', file->map_w + 2);
	file->map[i] = 0;
}

int		is_dir_flag(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	check_surround(t_file *file, int y, int x)
{
	if (x != 0 && !(file->map[y][x - 1] == '1' \
				|| file->map[y][x - 1] == ' '))
		error_out("Error\ninvalid map");
	if (y != 0 && !(file->map[y - 1][x] == '1' \
				|| file->map[y - 1][x] == ' '))
		error_out("Error\ninvalid map");
	if (x != file->map_w + 1 && !(file->map[y][x + 1] == '1' \
				|| file->map[y][x + 1] == ' '))
		error_out("Error\ninvalid map");
	if (y != file->map_h + 1 && !(file->map[y + 1][x] == '1' \
				|| file->map[y + 1][x] == ' '))
		error_out("Error\ninvalid map");
}

void	check_map(t_file *file)
{
	int i;
	int j;

	scan_map(file);
	append_map(file);
	i = -1;
	while (file->map[++i])
	{
		j = -1;
		while (file->map[i][++j])
		{
			if (!(file->map[i][j] == '1' || file->map[i][j] == '0' || file->map[i][j] == ' '))
			{
				if (!file->c_flag && is_dir_flag(file->map[i][j]))
					file->c_flag = 1;
				else
					error_out("Error\ninvalid map");
			}
			if (file->map[i][j] == ' ')
				check_surround(file, i , j);
		}
	}
	if (!file->c_flag)
		error_out("Error\ninvalid map");
}

void	check_file(t_file *file, char *path)
{
	init_file(file);
	file->str = read_file(path);
	file->split = ft_split(file->str, '\n');
	if (!file->split)
		error_out("Error\nsplit error");
	check_info(file);
	check_map(file);

	//
	printf("kk");
}


//main
int main(int ac, char *av[])
{
	t_file	file;
	t_game	game;

	if (ac != 2 || !is_cub_extension(av[1]))
		error_out("Error\nusage: ./cub3d [map.cub]");
	check_file(&file, av[1]);
		

	return (0);
}
