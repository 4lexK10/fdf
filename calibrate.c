/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:22:31 by akloster          #+#    #+#             */
/*   Updated: 2024/04/29 21:04:01 by akloster         ###   ########.fr       */
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
	/* printf("min_x %d min_y %d\n", min_x, min_y); */
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

static void	max_point(t_2d_grid *head, t_3d_grid **max_x, t_3d_grid **max_y)
{
	t_2d_grid	*x_2d;
	t_2d_grid	*y_2d;
	t_2d_grid	*temp;

	x_2d = head;
	y_2d = head;
	temp = head;
	while (temp != NULL)
	{
		if (temp->point.x > x_2d->point.x)
			x_2d = temp;
		if (temp->point.y > y_2d->point.y)
			y_2d = temp;
		temp = temp->next;
	}
	while (x_2d->next->point.x == x_2d->point.x)
		x_2d = x_2d->next;
	temp = head;
	while (temp != x_2d)
	{
		*max_x = (*max_x)->next;
		temp = temp->next;
	}
	while (head != y_2d)
	{
		*max_y = (*max_y)->next;
		head = head->next;
	}
}

static int	check_scale_up(t_2d_grid *head, t_3d_grid *head_3d)
{
	t_3d_grid	*min_x;
	t_3d_grid	*min_y;
	t_3d_grid	*max_x;
	t_3d_grid	*max_y;
	int			scale;

	scale = 2;
	min_x = head_3d;
	min_y = head_3d;
	max_x = head_3d;
	max_y = head_3d;
	min_point(head, &min_x, &min_y);
	max_point(head, &max_x, &max_y);
	printf("min x(%d, %d) max x(%d, %d)\n", min_x->x, min_x->y, max_x->x, max_x->y);
	printf("min y(%d, %d) max y(%d, %d)\n", min_y->x, min_y->y, max_y->x, max_y->y);
	while ((isometric_projection(max_x, 0, scale) - isometric_projection(min_x, 0, scale)) < WIDTH &&
	(isometric_projection(max_y, 1, scale) - isometric_projection(min_y, 1, scale)) < HEIGHT)
		++scale;
	return (scale - 1);
}

void	calibrate(t_2d_grid	*head, t_3d_grid *head_3d)
{
	t_2d_grid	*temp;
	t_3d_grid	*temp_3d;
	int			scale_up;

	temp_3d = head_3d;
	set_1st_quad(head);
	scale_up = check_scale_up(head, head_3d);
	/* printf("scale: %d\n", scale_up); */
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
