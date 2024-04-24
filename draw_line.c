/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:43:04 by akloster          #+#    #+#             */
/*   Updated: 2024/04/24 13:37:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_coordinates(t_2d_point *i, t_2d_point *f)
{
	int	temp;

	temp = i->x;
	i->x = i->y;
	i->y = temp;
	if (!f)
		return ;
	temp = f->x;
	f->x = f->y;
	f->y = temp;
}

static t_2d_point	bresenham_algo(t_2d_point i, t_2d_point f, int *param, t_2d_grid *head)
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

static	t_2d_grid	*create_2d_point(t_2d_grid **head, t_2d_point pixel, int res)
{
	t_2d_grid	*new_pixel;
	t_2d_grid	*temp;
	new_pixel = (t_2d_grid *)malloc(sizeof(t_2d_grid));
	if (!new_pixel)
		return (NULL);
/* 	if (res == 1 || res == 3)
		swap_coordinates(&pixel, NULL);
	if (res == 2 || res == 3)
		pixel.y *= -1; */
	new_pixel->point = pixel;
	/* printf("(%d %d)\n", pixel.x, pixel.y); */
	new_pixel->next = NULL;
	new_pixel->under = NULL;
	if (!(*head))
		*head = new_pixel;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_pixel;
	}
	return (*head);
}

static int	find_case(t_2d_point *i, t_2d_point *f)
{
	t_2d_point	temp;
	int			dx;
	int			dy;

	dx = f->x - i->x;
	dy = f->y - i->y;
	temp = *i;
	if (dx < 0)
	{
		*i = *f;
		*f = temp;
		return (find_case(i, f));
	}
	else if (dx * dy < 0)  // m < 0
	{
		i->y = -i->y;
		f->y = -f->y;
		return (find_case(i, f) + 2);
	}
	else if (dy > dx) // m > 1
		return (swap_coordinates(i, f), 1);
	return (0);
}

static void	switch_values(t_2d_grid *head, int res)
{
	while (head != NULL);
	{
		if (res == 1 || res == 3)
			swap_coordinates(&(head->point), NULL);
		if (res == 2 || res == 3)
			head->point.y *= -1;
		head = head->next;
	}
}

int	draw_line(t_2d_point i, t_2d_point f, t_data *img)
{
	t_2d_grid	*head;
	t_2d_point	pixel;
	int			decision_param;
	int			res;
	int			incr;

	head = NULL;
	res = find_case(&i, &f);
	incr = i.x;
	decision_param = 2 * (f.y - i.y) - (f.x - i.x);
	/* printf("(%d, %d) (%d, %d) %d\n", i.x, i.y, f.x, f.y, res); */
	while (incr <= f.x)
	{
		pixel = bresenham_algo(i, f, &decision_param, head);
		head = create_2d_point(&head, pixel, res);
		++incr;
	}
	switch_values(head, res);
	if (!head)
		return (grid_2d_lstclear(&head), 1);
	while (head != NULL)
	{
		my_mlx_pixel_put(img, head->point.x, head->point.y, 0xffffff);
		head = head->next;
	}
	return (grid_2d_lstclear(&head), 0);
}
