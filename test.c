#include "fdf.h"


void    put_circle(int r, int x, int y, t_data *img)
{
	while (y < 1080)
	{
		if (x == 1920)
		{
			x = 0;
			++y;
		}
		if ((pow(y - 540, 2)) + (pow(x - 960, 2)) == pow(r, 2)/* 
			|| (pow(y - 540, 2)) + (pow(x - 960, 2)) == pow(r, 2) + 1
			|| (pow(y - 540, 2)) + (pow(x - 960, 2)) == pow(r, 2) - 1 */) 
			my_mlx_pixel_put(img, x, 1080 - y, 0xffffffff);
		++x;
	}
}

void    put_square(int a, int center_x, int center_y, t_data *img)
{
	int	x;
	int	y;

	x = center_x - a/2;
	y = center_y - a/2;
	while (x != center_x + a/2)
		my_mlx_pixel_put(img, x++, y, 0xffffffff);
	while (y != center_y + a/2)
		my_mlx_pixel_put(img, x, y++, 0xffffffff);
	while (x != center_x - a/2)
		my_mlx_pixel_put(img, x--, y, 0xffffffff);
	while (y != center_y - a/2)
		my_mlx_pixel_put(img, x, y--, 0xffffffff);
}
/* int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	
	if(*(char *)&n == 1)
		printf("LE\n");
	return (0);
} */