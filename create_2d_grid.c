/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:43:13 by akloster          #+#    #+#             */
/*   Updated: 2024/04/21 23:54:47 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	matrix_calc(t_3d_grid *point_3d, int x)
{
	t_3x3	rota_3x3;
	t_3x1	a;
	t_3x1	b;

	//assign these values once in fdf.h or assign once in main
	rota_3x3.x_x = sqrt(3) / sqrt(6);
	rota_3x3.x_y = 0;
	rota_3x3.x_z = -(sqrt(3)) / sqrt(6);
	rota_3x3.y_x = 1 / sqrt(6);
	rota_3x3.y_y = 2 / sqrt(6);
	rota_3x3.y_z = 1 / sqrt(6);
	rota_3x3.z_x = sqrt(2) / sqrt(6);
	rota_3x3.z_y = -(sqrt(2)) / sqrt(6);
	rota_3x3.z_z = sqrt(2) / sqrt(6);
	a.x = point_3d->x;
	a.y = point_3d->y;
	a.z = point_3d->z;
	b.x = rota_3x3.x_x * a.x + rota_3x3.x_y * a.y + rota_3x3.x_z * a.z;
	b.y = rota_3x3.y_x * a.x + rota_3x3.y_y * a.y + rota_3x3.y_z * a.z;
	if (x == 1)
		return (round(b.x));
	return (round(b.y));
}

static	t_2d_grid	*create_2d_point(t_2d_grid *head, t_3d_grid *temp_3d)
{
	t_2d_grid	*new_point;
	t_2d_grid	*temp;
	new_point = (t_2d_grid *)malloc(sizeof(t_2d_grid));
	if (!new_point)
		return (NULL);
	new_point->x = matrix_calc(temp_3d, 1);
	new_point->y = matrix_calc(temp_3d, 0);
	new_point->next = NULL;
	new_point->under = NULL;
	if (!head)
		head = new_point;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_point;
	}
	return (head);
}

static void	vertical_link(t_2d_grid *grid_2d, t_3d_grid *grid_3d)
{
	int			cnt;
	t_2d_grid 	*shift;

	cnt = 1;
	shift = grid_2d;
	while (grid_3d->next->x != 0)
	{
		++cnt;
		grid_3d = grid_3d->next;
	}
	while (cnt--)
		shift = shift->next;
	while (shift != NULL)
	{
		grid_2d->under = shift;
		shift = shift->next;
		grid_2d = grid_2d->next;
	}
	while (grid_2d != NULL)
	{
		grid_2d->under = NULL;
		grid_2d = grid_2d->next;
	}
}

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
		if (temp->x < min_x)
			min_x = temp->x;
		if (temp->y < min_y)
			min_y = temp->y;
		temp = temp->next;
	}
	printf("min_x %d min_y %d\n", min_x, min_y);
	temp = head;
	if (min_x < 0 || min_y < 0)
	{
		while (temp != NULL)
		{
			temp->x += -min_x;
			temp->y += -min_y;
			temp = temp->next;
		}
	}
}

t_2d_grid	*create_2d_grid(t_3d_grid *head_3d)
{
	t_2d_grid	*head;
	t_2d_grid	*temp;
	t_3d_grid	*temp_3d;

	if (!head_3d)
		return (NULL);
	temp_3d = head_3d->next;
	head = NULL;
	head = create_2d_point(head, head_3d);
	if (!head)
		return (grid_3d_lstclear(&head_3d), NULL);
	while (temp_3d != NULL)
	{
		temp = create_2d_point(head, temp_3d);
		if (!temp)
			return (grid_3d_lstclear(&head_3d), grid_2d_lstclear(&head), NULL);
		temp_3d = temp_3d->next;
	}
	vertical_link(head, head_3d);
	set_1st_quad(head);
/* 	for (t_2d_grid *temp = head; temp != NULL; temp = temp->next)
	{	
		printf("(%d, %d) ", temp->x, temp->y);
		if (temp->next != NULL && temp->next->x < temp->x)
			printf("\n");
	}
	printf("\n");
	for (t_2d_grid *temp = head->next; temp != NULL; temp = temp->under)
	{	
		printf("(%d, %d)\n", temp->x, temp->y);
	}
	printf("\n");
	for (t_3d_grid *temp = head_3d; temp != NULL; temp = temp->next)
	{	
		printf("(%d, %d) ", temp->x, temp->y);
		if (temp->next != NULL && temp->next->x < temp->x)
			printf("\n");
	}
	printf("\n"); */
	return (grid_3d_lstclear(&head_3d), head);
}
