/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:11:19 by akloster          #+#    #+#             */
/*   Updated: 2024/04/21 16:21:14 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	create_3d_point(char *z_coordinate_char, t_3d_grid **head, int x, int y)
{
	t_3d_grid *temp;
	t_3d_grid *new_point;
	temp = *head;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	new_point = (t_3d_grid *)malloc(sizeof(t_3d_grid));
	if (!new_point)
		return (-1);
	new_point->x = x * 25;
	new_point->y = y * 25;
	new_point->z = ft_atoi(z_coordinate_char) * 25;
	new_point->next = NULL;
	if (!temp)
		*head = new_point;
	else
		temp->next = new_point;
	return (0);
}

static int	create_row(int fd, t_3d_grid **head, int y)
{
	char	*line;
	char	**z_coordinates_char;
	int		x;

	line = get_next_line(fd);
	if (!line)
		return (1);
	z_coordinates_char = ft_split(line, ' ');
	free(line);
	if (!z_coordinates_char)
		return (-1);
	x = 0;
	while (z_coordinates_char[x] != NULL)
	{
		if (create_3d_point(z_coordinates_char[x], head, x, y) == -1)
			return (free_ptr_array(&z_coordinates_char), -1);
		++x;
	}
	free_ptr_array(&z_coordinates_char);
	return (0);
}

t_3d_grid	*create_3d_grid(int fd)
{
	t_3d_grid	*head;
	int			y;
	int			res;

	head = NULL;
	y = 0;
	res = create_row(fd, &head, y);
	while (res == 0) // try (!res)
	{
		++y;
		res = create_row(fd, &head, y);
	}
	if (res == -1) // try (res)
		grid_3d_lstclear(&head);
/* 	for (t_3d_grid *temp = head; temp != NULL; temp = temp->next)
	{
		printf("(%d, %d, z) ", temp->x, temp->y);
	}
	printf("\n"); */
	return (head);
}
