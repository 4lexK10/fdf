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
	put_circle(100, 400, 400, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
