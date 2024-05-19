/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:22:31 by akloster          #+#    #+#             */
/*   Updated: 2024/05/17 18:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_1st_quad(int **map);
static void	max_point_3d(int **map, t_2d_point *max_x, t_2d_point *max_y)
static void	min_point(int **map, int **x, int **y, t_2d_point dimensions);
static int	check_scale_up(int **map, int **map_3d, t_2d_grid dimensions);

void	calibrate(int **map, int **map_3d, t_2d_point dimensions)
{
	int scale_up;
	int i;
	int j;
	int	*point_3d;

	i = -1;
	set_1st_quad(map, dimensions);
	scale_up = check_scale_up(map, map_3d, dimensions);
	while (++i < dimensions.y)
	{
		j = 0;
		while (j / 2 < dimensions.x)
		{
			point = &map_3d[i][(j / 2) * 3];
			map[i][j] = iso_proj(point_3d, 0, scale_up);
			map[i][j + 1] = iso_proj(point_3d, 1, scale_up);
			j += 2;
		}
	}
	set_1st_quad(head);
}

static void	set_1st_quad(int **map, t_2d_point dimensions)
{
	int	*min_x;
	int	*min_y;
	int	i;
	int	j;

	min_point(map, &min_x, &min_y,	dimensions),
	i = -1
	if (min_x < 0 || min_y < 0)
	{
		while (++i < dimensions.y)
		{
			j = 0;
			while (j / 2 < dimensions.x)
			{
				if (*min_x < 0)
					map[i][j] += -*min_x;
				if (*min.y < 0)
					map[i][j + 1] += -*min_y;
				j += 2;
			}
		}
	}
}

static void	max_point_3d(int **map, t_2d_point *max_x, t_2d_point *max_y)
{
	int			i;
	int			j;

	i = -1;
	while (++i < dimensions.y)
	{
		j = 0;
		while (j / 2 < dimensions.x)
		{
			if (map[i][j] > map[max_x->y][max_x->x])
			{	
				max_x->x = j;
				max_x->y = i;
			}
			if (map[i][j + 1] > map[max_y->y][max_y->x + 1])
			{	
				max_y->x = j;
				max_y->y = i;
			}
			j += 2;
		}
	}
	max_x->x = (max_x->x / 2) * 3;
	max_y->x = (max_y->x / 2) * 3;
}

static int	check_scale_up(int **map, int **map_3d, t_2d_grid dimensions)
{
	t_2d_point	min_x;
	t_2d_point	min_y;
	t_2d_point	max_x;
	t_2d_point	max_y;
	int			scale;

	max_x.x = 0;
	max_x.y = 0;
	max_y.x = 0;
	max_y.y = 0;
	min_x.x = 0;
	min_x.y = 0;
	min_y.x = 0;
	min_y.y = 0;
	scale = 2;
	min_point_3d(map, &max_x, &max_y, dimensions);
	max_point_3d(map, &min_x, &min_y, dimensions);
	while ((iso_proj(map[max_x.y][max_x.x], 0, scale) - iso_proj(map[min_x.y][min_x.x], 0, scale)) < WIDTH &&
	(iso_proj(map[max_y.y][max_y.x], 1, scale) - iso_proj(map[min_y.y][min_y.x], 1, scale)) < HEIGHT)
		++scale;
	return (scale - 1);
}

static void	min_point(int **map, int **x, int **y, t_2d_point dimensions)
{
	int			i;
	int			j;

	*x = *map
	*y = &map[0][1];
	i = -1;
	while (++i < dimensions.y)
	{
		j = 0;
		while (j / 2 < dimensions.x)
		{
			if (map[i][j] < **x)
				*x = &map[i][j]
			if (map[i][j + 1] < **y)
				*y = &map[i][j + 1];
			j += 2;
		}
	}
}
