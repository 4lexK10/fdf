#include "fdf.h"

static int	fill_line(int *line, int y, int max_x, int **map);

int	**create_2d(int **map_3d)
{
	int	i;
	int	y;
	int	**map;

	i = -1;
	y = -1;
	map = (int **)malloc(sizeof(int *) * dimensions.y);
	if (!map)
		return (NULL);
	while (++i < dimensions.y)
	{
		map[i] = (int *)malloc(sizeof(int) * (dimensions.x * 3));
		if (!map[i])
			return (free_map(&map), free_map(&map_3d), NULL);
	}
	while (++y < dimensions.y)
		fill_lines(map[y], y, dimensions.x, map_3d);
}

static void	fill_line(int *line, int y, int max_x, int **map)
{
	int	i;
	int	x;

	i = -1;
	x = -1;
	while (++x < max_x)
	{
		line[++i] = (int)(sqrt(2) / 2 * ((scale * map[y][x]) - (scale * map[y][x + 1]))); 
		line[++i] = (int)(sqrt(6) / 6 * ((scale * map[y][x]) + (scale * map[y][x + 1])) - sqrt(4) / 3 * (scale * map[y][x + 2]));
	}
}

