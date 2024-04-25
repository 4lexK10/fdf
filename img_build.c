/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:32:51 by akloster          #+#    #+#             */
/*   Updated: 2024/04/25 22:11:09 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}



/* void	calibrate(t_2d_grid	*head)
{
	t_2d_grid	*max_x;
	t_2d_grid	*max_y;
	t_2d_grid	*temp;
	int			scale_up;

	scale_up = 1;
	max_x = head;
	max_y = head;
	temp = head->next;
	while (temp != NULL)
	{
		if (max_x->point.x < temp->point.x)
			max_x = temp;
		if (max_y->point.y < temp->point.y)
			max_y = temp;
		temp = temp->next;
	}
	// printf("test%p %p\n", temp_3d_x, temp_3d_y);
	// printf("test %f\n", scale_up * (sqrt(6) / 6 * (temp_3d_y->x + temp_3d_y->y) - sqrt(6) / 3 * temp_3d_y->z));
	while (scale_up * max_x->point.x < 2300 && scale_up * max_y->point.y < 1300)
	{
		++scale_up;
	}
	printf("%d\n", scale_up);
	while (head != NULL)
	{
		head->point.x *= (scale_up - 1);
		head->point.y *= (scale_up - 1);
		head = head->next;
	}
} */

void	set_1st_quad(t_2d_grid *head)
{
	int			min_x;
	int			min_y;
	t_2d_grid	*temp;

	min_x = 0;
	min_y = 0;
	temp = head;
	while (temp != NULL)
	{
		if (temp->point.x < min_x)
			min_x = temp->point.x;
		if (temp->point.y < min_y)
			min_y = temp->point.y;
		temp = temp->next;
	}
	printf("min_x %d min_y %d\n", min_x, min_y);
	temp = head;
	if (min_x < 0 || min_y < 0)
	{
		while (temp != NULL)
		{
			temp->point.x += -min_x;
			temp->point.y += -min_y;
			temp = temp->next;
		}
	}
}

int	abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}
