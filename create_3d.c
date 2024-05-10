/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:03:22 by akloster          #+#    #+#             */
/*   Updated: 2024/05/08 21:18:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*clean_line(char *str);
static char		*fill_line(int ***map, int fd);

int	**create_3d(fd, t_2d_point dimensions)
{
	int		i;
	int		y;
	int		**map;

	i = -1;
	y = -1;
	map = (int **)malloc(sizeof(int *) * dimensions.y);
	if (!map)
		return (NULL);
	while (++i < dimensions.y)
	{
		map[i] = (int *)malloc(sizeof(int) * (dimensions.x * 3));
		if (!map[i])
			return (fr_map(&map), NULL);
	}
	while (++y < dimensions.y)
	{
		if (fill_lines(map[y], y, dimensions.x, fd) == FAIL)
			return (free_map(&map), NULL);
	}
	return (map);
}

static int	fill_line(int *line, int y, int max_x,	int fd)
{
	char	*output;
	char	**raw_z;
	int	x;
	int	i;

	x = 0;
	i = -1;
	output = clean_line(get_next_line(fd)); 
	raw_z = ft_split(output);
	if (!raw_z)
		return (my_free(&output), FAIL);
	while (x < max_x)
	{
		line[++i] = x;
		line[++i] = y;
		line[++i] = ft_atoi(raw_z[x++]);
	}
	return (SUCCESS);
}

static t_2d_point	get_array_dimensions(int fd)
{
	t_2d_point	dimensions;
	t_2d_point	failed;
	char		**line;
	char		*output;

	dimensions.x = 0;
	dimensions.y = 1;
	failed.x = -1;
	failed.y = -1;
	output = clean_line(get_next_line(fd));
	line = ft_split(output);
	my_free(&output);
	if (!line)
		return (failed);
	while (*line++ != NULL)
		++dimensions.x;
	output = get_next_line(fd);
	while (output != NULL)
	{
		++dimensions.y;
		my_free(&output);
		output = get_next_line(fd);
	}
	return (close(fd), dimensions);
}


static char *clean_line(char *str)
{
	char *line;

	line = ft_strtrim(str, "\n");
	free(str);
	if (!line)
		return (NULL);
	return (line);
}

