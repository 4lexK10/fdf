/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:03:22 by akloster          #+#    #+#             */
/*   Updated: 2024/05/17 19:43:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*clean_line(char *str);
static char		*fill_line(int ***map, int fd);

int	**create_3d(fd, t_2d_point dimensions)
{
	int		i;
	int		**map;

	i = -1;
	map = (int **)malloc(sizeof(int *) * dimensions.y);
	if (!map)
		return (NULL);
	while (++i < dimensions.y)
	{
		map[i] = (int *)malloc(sizeof(int) * (dimensions.x * 3));
		if (!map[i] || fill_lines(map[i], y, dimensions.x, fd) == FAIL)
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
	raw_z = ft_split(output);  // check if split is protected if NULL is passed
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

static void	clean_line(char **str)
{
	char *line;

	if (!(*str))
		return ;
	line = ft_strtrim(*str, "\n");
	my_free(str);
	if (!line)
		return ;
	*str = line;
}
