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
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
/* 	char	*str;
	int		fd; */

	if (ac != 2)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window (mlx , 1920, 1080, av[1]);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 660, 540, 0xffffffff);
	x = 0;
	/* circle = sqrt((r - x)^2 + (r - y)^2) */
/* 	while (x < 500)
		my_mlx_pixel_put(&img, 660 + x++, 540, 0xffffffff); */
	my_mlx_pixel_put(&img, 950, 540, 0xffffffff);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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
