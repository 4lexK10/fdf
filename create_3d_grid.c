/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:11:19 by akloster          #+#    #+#             */
/*   Updated: 2024/05/01 19:06:07 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* static int	get_color(char *str)
{
	char	**raw_nbr;
	int		nbr;
	int		i;

	i = 0;
	raw_nbr = ft_split(str, 'x');
	if (!raw_nbr)
		return (-1);
	if (ft_memcmp(str, raw_nbr[0], ft_strlen(str)) == 0)
		return (free_ptr_array(&raw_nbr), 16777215);
	while (raw_nbr[1][i] != '\0')
	{
		nbr = nbr * 16;
		if (ft_isalnum(raw_nbr[1][i]) == 4)
			nbr += raw_nbr[1][i] - '0';
		if (ft_isalnum(raw_nbr[1][i]) == 1)
			nbr += raw_nbr[1][i] - '7';
		if (ft_isalnum(raw_nbr[1][i]) == 2)
			nbr += raw_nbr[1][i] - 'W';
		++i;
	}
	return (free_ptr_array(&raw_nbr), nbr);
} */

static int	create_3d_point(char *z_coordinate_char, t_3d_grid **head, int x, int y)
{
	t_3d_grid	*temp;
	t_3d_grid	*new_point;

	temp = *head;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	new_point = (t_3d_grid *)malloc(sizeof(t_3d_grid));
	if (!new_point)
		return (-1);
	new_point->x = x;
	new_point->y = y;
	new_point->z = ft_atoi(z_coordinate_char);
	/* printf("%d ", new_point->x); */
	new_point->color = 0xffffff; //get_color(z_coordinate_char);
	if (new_point->color == -1)
		return (free(new_point), -1);
	/* printf("color%d\n", new_point->color); */
	new_point->next = NULL;
	if (!temp)
		*head = new_point;
	else
		temp->next = new_point;
	return (0);
}

static char *clean_line(char *str)
{
	char *line;

	line = ft_strtrim(str, "\n");
	free(str);
	if (!line)
		return (NULL);
	return (line);
}

static int	create_row(int fd, t_3d_grid **head, int y)
{
	char	*line;
	char	**z_coordinates_char;
	int		x;

	line = clean_line(get_next_line(fd));
	if (!line)
		return (1);
	z_coordinates_char = ft_split(line, ' ');
/* 	for (int i = 0; z_coordinates_char[i] != NULL; ++i)
		printf("|%s|\n", z_coordinates_char[i]); */
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
