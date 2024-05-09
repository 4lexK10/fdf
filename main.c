/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:23:00 by akloster          #+#    #+#             */
/*   Updated: 2024/03/23 10:23:00 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_clmn_nbr(t_3d_grid *head)
{
	int		i;

	i = 1;
/* 	for (t_3d_grid *temp = head; temp != NULL; temp = temp->next)
	{
		printf("(%d, %d, %d) ", temp->x, temp->y, temp->z);
		if (temp->next != NULL && temp->next->x < temp->x)
			printf("\n");
	}
	printf("\n"); */
	while (head->x < head->next->x)
	{
		++i;
		head = head->next;
	}
	return (i);
}


static void	put_grid(int **map, t_data *img, t_2d_point dimensions)
{
	int			**temp;
	int			x;
	int			y;
	t_2d_point	i;
	t_2d_point	f;

	y = -1;
	temp = map;
	while (++y < dimensions.y)
	{
		x = 0;
		while (x / 2 < dimensions.x - 1)
		{
			i.x = map[y][x];
			i.y = map[y][x + 1];
			f.x = map[y][x + 2];
			f.y = map[y][x + 3];
			draw_line(i, f, img);
			x += 2;
		}
	}
	x = 0;
	while (x / 2 < dimensions.x)
	{
		y = -1;
		while (++y < dimensions.y - 1)
		{
			i.x = map[y][x];
			i.y = map[y][x + 1];
			f.x = map[y + 1][x];
			f.y = map[y + 1][x + 1];
			draw_line(i, f, img);
		}
		x += 2;
	}
}

static	int	create_load_map(/* t_data *img,  */char *path)
{
	t_2d_grid	*head_2d;
	t_3d_grid	*head_3d;
	int			fd;
	int			nbr;

	head_2d = NULL;
	head_3d = NULL;
	fd = open(path, O_RDONLY);
	
	printf("test\n");
	head_3d = create_3d_grid(fd);
	close(fd);
	if (!head_3d)
		return (1);
	nbr = get_clmn_nbr(head_3d);
/* 	head_2d = create_2d_grid(head_3d);
	if (!head_2d)
		return (grid_3d_lstclear(&head_3d), 1);
	calibrate(head_2d, head_3d);
	put_grid(head_2d, img, nbr); */
	/* printf("test\n"); */
	return (/* grid_3d_lstclear(&head_3d),  */0);
}

int main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	if (ac != 2)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window (mlx , WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
/* 	for (t_2d_grid *tempi = head_2d; tempi->next->x > tempi->x; tempi = tempi->next)
	{
		for (t_2d_grid *temp = tempi; temp != NULL; temp = temp->under)
			my_mlx_pixel_put(&img, temp->x, temp->y, 0xffffff);
	} */
/* 	for (t_2d_grid *temp = head_2d->next->next; temp != NULL; temp = temp->under)
		my_mlx_pixel_put(&img, temp->x, temp->y, 0xffffff); */
/* 	for (t_2d_grid *temp = head_2d; temp != NULL; temp = temp->next)
	{	
		printf("(%d, %d) ", temp->point->x, temp->point->y);
		if (temp->next != NULL && temp->next->point->x < temp->point->x)
			printf("\n");
	} */
/* 	for (t_2d_grid *tempi = head_2d; tempi->next->point.x > tempi->point.x; tempi = tempi->next)
	{
		for (t_2d_grid *temp = tempi; temp != NULL; temp = temp->under)
			my_mlx_pixel_put(&img, temp->point.x, temp->point.y, 0xffffff);
	} */
/* 	for (t_2d_grid *temp = head_2d; temp != NULL; temp = temp->next)
	{	
		printf("(%d, %d) ", temp->point.x, temp->point.y);
		if (temp->next != NULL && temp->next->point.x < temp->point.x)
			printf("\n");
	} */
/* 	for (t_2d_grid *tempi = head_2d; (nbr--) >= 0; tempi = tempi->next)
	{
		for (t_2d_grid *temp = tempi; temp != NULL; temp = temp->under)
			my_mlx_pixel_put(&img, temp->point.x, temp->point.y, 0xffffff);
	} */
	if (create_load_map(/* &img,  */av[1]))
		return (0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
