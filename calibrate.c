/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:22:31 by akloster          #+#    #+#             */
/*   Updated: 2024/05/10 22:34:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_1st_quad(int **map);
static void	max_point(int **map, int **map_3d, t_2d_point *x, t_2d_point *y);
static void	min_point(int **map, int **x, int **y, t_2d_point dimensions);
static int	check_scale_up(int **map, t_2d_grid dimensions);

void	calibrate(int **map, int **map_3d, t_2d_point dimensions)
{
	int scale_up;

	set_1st_quad(map, dimensions);
	scale_up = check_scale_up(head, head_3d, dimensions);
	temp = head;
	while (temp != NULL)
	{
		temp->point.x = isometric_projection(head_3d, 0, scale_up);
		temp->point.y = isometric_projection(head_3d, 1, scale_up);
		temp = temp->next;
		head_3d = head_3d->next;
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

static void	max_point(int **map, int **map_3d, t_2d_point *x, t_2d_point *y)
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
			if (map[i][j] > **x)
				*x = &map[i][j]
			if (map[i][j + 1] > **y)
				*y = &map[i][j + 1];
			j += 2;
		}
	}
}

static int	check_scale_up(int **map, t_2d_grid dimensions)
{
	t_2d_point	min_x;
	t_2d_point	min_y;
	t_2d_point	max_x;
	t_2d_point	max_y;
	int			scale;

	scale = 2;
	min_point_3d(map, &min_x, &min_y, dimensions); // need fct that takes map_3d and map to find min/max 2d and corresponding 3d point 
	max_point_3d(map, &min_x, &min_y, dimensions);
	while ((isometric_projection(max_x, 0, scale) - isometric_projection(min_x, 0, scale)) < WIDTH &&
	(isometric_projection(--max_y, 1, scale) - isometric_projection(--min_y, 1, scale)) < HEIGHT)
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
