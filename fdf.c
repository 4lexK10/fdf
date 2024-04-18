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

int main(int ac, char **av)
{
/* 	void	*mlx;
	void	*mlx_win;
	t_data	img; */
/* 	char	*str;
	int		fd; */
	int		fd;
	t_3d_grid	*head_3d;
	t_2d_grid	*head_2d;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	head_3d = NULL;
	head_2d = NULL;
	head_3d = create_3d_grid(fd, &head_3d);
	if (!head_3d)
		return (0);
	head_2d = create_2d_grid(&head_3d);
	if (!head_2d)
		return (grid_lstclear(&head_3d), 0);
/* 	mlx = mlx_init();
	if (!mlx)
		return (0); */
	/*
	int fd;
	t_3d_grid	*head;

	fd = open(av[1], O_RDONLY);
	head = NULL;

	create_3d_grid(fd, &head);	<-- gnl all of .fdf 
							x = hor_pos, y = ver_pos, z = value
	create_2d_grid();	<-- for each point of the 3d_grid
							- (1) apply rotation matrices
							- (2) apply orthographic projection


	*/
/* 	mlx_win = mlx_new_window (mlx , 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian); */
	//my_mlx_pixel_put(&img, 660, 540, 0xffffffff);
	/* circle = sqrt((r - x)^2 + (r - y)^2) */
	/* 
		int		x;
		int		y

		while (y < 1080 && x < 1920)
		{
			if (rond(pow(y) + pow(x)) == rond(pow(r)))
				my_mlx_pixel_put(&img, x, y, 0xffffffff);
			++x;
			++y
		}
	*/
/* 	while (x < 500)
		my_mlx_pixel_put(&img, 660 + x++, 540, 0xffffffff); */
/* 	put_circle(100, 0, 0, &img);
	put_square(100, 300, 300, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); */
/* 	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
		get_full_axis();
	} */
	return (0);
}
