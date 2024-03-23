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
	void	*img;
	char	*str;
	int		fd;

	if (ac != 2)
		return (0);
	mlx = mlx_init();
	/* mlx_loop(mlx); */
	img = mlx_new_image(mlx, 1920, 1080);


	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
		/* get_full_axis(); */
	}
	return (0);
}
