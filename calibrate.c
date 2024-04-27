/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:22:31 by akloster          #+#    #+#             */
/*   Updated: 2024/04/27 21:39:06 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_1st_quad(t_2d_grid *head)
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

static int	check_scale_up(t_2d_grid *head, t_3d_grid *head_3d)
{
	t_3d_grid	*least_x;
	t_3d_grid	*least_y;
	t_3d_grid	*far_x;
	t_3d_grid	*far_y;
	int			scale;

	scale = 2;
	least_x = head_3d;
	least_y = head_3d;
	far_x = head_3d;
	far_y = head_3d;
	while (far_x->next->x > far_x->x)
		far_x = far_x->next;
	while (far_y->next != NULL)
		far_y = far_y->next;
	printf("%p\n", far_y);
	min_point(head, &least_x, &least_y);
	printf("(%d, %d) (%d, %d)\n", least_x->x, least_x->y, far_x->x, far_x->y);
	printf("(%d, %d) (%d, %d)\n", least_y->x, least_y->y, far_y->x, far_y->y);
	while ((isometric_projection(far_x, 0, scale) - isometric_projection(least_x, 0, scale)) < WIDTH &&
	(isometric_projection(far_y, 1, scale) - isometric_projection(least_y, 1, scale)) < HEIGHT)
		++scale;
	printf("test\n");
	--scale;
	return (scale);
}

void	calibrate(t_2d_grid	*head, t_3d_grid *head_3d)
{
	t_2d_grid	*temp;
	t_3d_grid	*temp_3d;
	int			scale_up;

	temp_3d = head_3d;
	set_1st_quad(head);
	scale_up = check_scale_up(head, head_3d);
	printf("scale: %d\n", scale_up);
	temp = head;
	while (temp != NULL)
	{
		temp->point.x = isometric_projection(head_3d, 0, scale_up);
		temp->point.y = isometric_projection(head_3d, 1, scale_up);
		temp = temp->next;
		head_3d = head_3d->next;
	}
	set_1st_quad(head);
/* 	for (t_2d_grid *temp = head; temp != NULL; temp = temp->next)
	{
		printf("(%d, %d) ", temp->point.x, temp->point.y);
		if (temp->next != NULL && temp->point.x > temp->next->point.x)
			printf("\n");
		if (temp->next == NULL)
			printf("(%d, %d)\n", temp->next->point.x, temp->next->point.y);
	} */
}
