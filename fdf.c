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

	while (head->x < head->next->x)
		head = 
	return (i);
}


static void	put_grid(t_2d_grid *head, t_data *img, int clmn_nbr)
{
	t_2d_grid	*temp;
	int			pos;

	pos = 1;
	temp = head;
	printf("column nbr: %d\n", clmn_nbr);
	while (temp->next != NULL)
	{
		// printf("f.x%d i.x%d\n", temp->next->x, temp->x);
		if (pos == clmn_nbr)
		{
			temp = temp->next;
			pos = 1;
		}
		draw_line(temp->point, temp->next->point, img);
		temp = temp->next;
		++pos;
	}
	pos = 1;
	while (pos < clmn_nbr + 1)
	{
		temp = head;
		while (temp->under != NULL)
		{
			draw_line(temp->point, temp->under->point, img);
			temp = temp->under;
		}
		head = head->next;
		++pos;
	}
}

int main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	int			fd;
	t_2d_grid	*head_2d;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	head_2d = NULL;
	head_2d = create_2d_grid(create_3d_grid(fd));
	close(fd);
	if (!head_2d)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window (mlx , 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
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
	int nbr = get_clmn_nbr(av[1]);
	for (t_2d_grid *tempi = head_2d; (nbr--) >= 0; tempi = tempi->next)
	{
		for (t_2d_grid *temp = tempi; temp != NULL; temp = temp->under)
			my_mlx_pixel_put(&img, temp->point.x, temp->point.y, 0xffffff);
	}
	put_grid(head_2d, &img, nbr);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
