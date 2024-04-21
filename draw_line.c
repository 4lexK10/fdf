/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:43:04 by akloster          #+#    #+#             */
/*   Updated: 2024/04/21 23:54:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_coordinates(t_2d_point *i, t_2d_point *f)
{
	int	temp;

	temp = i->x;
	i->x = i->y;
	i->y = temp;
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
		pixel.x = head->x;
		pixel.y = head->y;
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

static	t_2d_grid	*create_2d_point(t_2d_grid **head, int x, int y)
{
	t_2d_grid	*new_pixel;
	t_2d_grid	*temp;
	new_pixel = (t_2d_grid *)malloc(sizeof(t_2d_grid));
	if (!new_pixel)
		return (NULL);
	new_pixel->x = x;
	new_pixel->y = y;
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
	t_2d_point	*temp;

	temp = i;
	if (f->x - i->x < 0)
	{
		*i = *f;
		*f = *temp;
	}		
	else if ((f->x - i->x) * (f->y - i->y) < 0)
	{
		i->y = -i->y;
		f->y = -f->y;
		return (find_case(i, f) + 2);
	}
	else if ((f->y - i->y) > (f->x - i->x))
	{
		swap_coordinates(i, f);
		return (1);
	}
	return (0);
}

int	draw_line(t_2d_point i, t_2d_point f, t_data *img)
{
	t_2d_grid	*head;
	t_2d_point	pixel;
	int			decision_param;
	int			res;

	head = NULL;
	decision_param = 2 * (f.x - i.x) - (f.y - i.y);
	res = find_case(&i, &f);
	/* printf("(%d, %d) (%d, %d) %d\n", i.x, i.y, f.x, f.y, res); */
	while (pixel.x <= f.x)
	{
		pixel = bresenham_algo(i, f, &decision_param, head);
		if (res == 2)
			head = create_2d_point(&head, pixel.x, -pixel.y);
		else if (res == 1)
			head = create_2d_point(&head, pixel.y, pixel.x);
		else if (res == 3)
			head = create_2d_point(&head, pixel.y, -pixel.x);
		else
			head = create_2d_point(&head, pixel.x, pixel.y);
	}
	if (!head)
		return (grid_2d_lstclear(&head), 1);
	while (head != NULL)
	{
		my_mlx_pixel_put(img, head->x + 100, head->y + 100, 0xffffff);
		head = head->next;
	}
	return (grid_2d_lstclear(&head), 0);
}