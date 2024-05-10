/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:32:51 by akloster          #+#    #+#             */
/*   Updated: 2024/05/10 20:24:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	isometric_projection(int *point, int want_y, int scale)
{
	int	x;
	int	y;

	x = (int)(sqrt(2) / 2 * ((scale * point[0]) - (scale * point[1])));
	y = (int)(sqrt(6) / 6 * ((scale * point[0]) + (scale * point[1])) - sqrt(4) / 3 * (scale * point[2]));
	if (want_y)
		return (y);
	return (x);
}
