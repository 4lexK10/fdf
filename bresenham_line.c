/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:43:04 by akloster          #+#    #+#             */
/*   Updated: 2024/04/20 17:15:43 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	swap_coordinates(int *x0, int *x1, int *y0, int *y1)
{
	int	temp;

	temp = *x0;
	*x0 = *y0;
	*y0 = temp;
	temp = *x1;
	*x1 = *y1;
	*y1 = temp;
	return (1);
}

/* static	void	put_pixel(int x, int y)
{
	my_mlx_pixel_put(img)
} */

int	bresenham_algo(t_2d_point i, t_2d_point f, t_data *img)
{
	int			dx;
	int			dy;
	int			decision_param;
	t_2d_point	point;

	if (f.y > i.y)
		decision_param = swap_coordinates(&i.x, &f.x, &i.y, &f.y);
	point.x = i.x;
	point.y = i.y;
	dx = f.x - i.x;
	dy = f.y - i.y;
	decision_param = 2 * dy - dx;
	while (point.x <= f.x)
	{
		my_mlx_pixel_put(img, point.x + 100, point.y + 100, 0xffffffff);  // needs offset x , y fct()
		if (decision_param < 0)
			decision_param += 2 * dy;
		else
		{
			decision_param += 2 * dy - 2 * dx;
			++point.y; 
		}
		++point.x;
	}
	return (0);
}
