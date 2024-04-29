/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:32:51 by akloster          #+#    #+#             */
/*   Updated: 2024/04/29 20:20:57 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	isometric_projection(t_3d_grid *point_3d, int want_y, int scale)
{
	int	x;
	int	y;

	x = (int)(sqrt(2) / 2 * ((scale * point_3d->x) - (scale * point_3d->y)));
	y = (int)(sqrt(6) / 6 * ((scale * point_3d->x) + (scale * point_3d->y)) - sqrt(4) / 3 * (scale * point_3d->z));
	if (want_y)
		return (y);
	return (x);
}

void	min_point(t_2d_grid *head, t_3d_grid **min_x, t_3d_grid **min_y)
{
	t_2d_grid	*temp;
	t_2d_grid	*min_point_x;
	t_2d_grid	*min_point_y;

	min_point_x = head;
	min_point_y = head;
	temp = head;
	while (temp != NULL)
	{
		if (temp->point.x < min_point_x->point.x)
			min_point_x = temp;
		if (temp->point.y < min_point_y->point.y)
			min_point_y = temp;
		temp = temp->next;
	}
	temp = head;
	while (temp != min_point_x)
	{
		temp = temp->next;
		*min_x = (*min_x)->next;
	}
	while (head != min_point_y)
	{
		head = head->next;
		*min_y = (*min_y)->next;
	}
}
