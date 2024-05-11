/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:32:51 by akloster          #+#    #+#             */
/*   Updated: 2024/05/11 17:39:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	iso_proj(int *point, int want_y, int scale)
{
	int	x;
	int	y;

	x = (int)(sqrt(2) / 2 * ((scale * point[0]) - (scale * point[1])));
	y = (int)(sqrt(6) / 6 * ((scale * point[0]) + (scale * point[1])) - sqrt(4) / 3 * (scale * point[2]));
	if (want_y)
		return (y);
	return (x);
}

void	min_point_3d(int **map, t_2d_point *min_x, t_2d_point *min_y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < dimensions.y)
	{
		j = 0;
		while (j / 2 < dimensions.x)
		{
			if (map[i][j] < map[min_x->y][min_x->x])
			{	
				min_x->x = j;
				min_x->y = i;
			}
			if (map[i][j + 1] < map[min_y->y][min_y->x + 1])
			{	
				min_y->x = j;
				min_y->y = i;
			}
			j += 2;
		}
	}
	min_x->x = (min_x->x / 2) * 3;
	min_y->x = (min_y->x / 2) * 3;
}

t_2d_point	bresenham_algo(t_2d_point i, t_2d_point f, int *param, t_2d_grid *head)
{
	t_2d_point pixel;

	pixel = i;
	if (!head)
		return (pixel);
	else
	{
		while (head->next != NULL)
			head = head->next;
		pixel = head->point;
	}
	if (*param < 0)
		*param += 2 * (f.y - i.y);
	else
	{
		*param += 2 * (f.y - i.y) - 2 * (f.x - i.x);
		++pixel.y;
	}
	++pixel.x;
	return (pixel);
}
