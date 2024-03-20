#include "fdf.h"

int main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd) != NULL)
	{

	}
}
