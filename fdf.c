#include "fdf.h"

int main(int ac, char **av)
{
	//int	fd;
	void	*mlx;
	void	*mlx_win;
	
	if (ac != 2)
		return (0);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, av[1]);
	if (mlx_win == NULL)
		return (0);
	mlx_loop(mlx);
	//fd = open(av[1], O_RDONLY);
	/*while (get_next_line(fd) != NULL)
	{
		get_full_axis();
	}*/
	return (0);
}
