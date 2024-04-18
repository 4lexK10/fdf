#include "fdf.h"

t_2d_grid	*create_line(t_2d_grid *head)
{
	t_2d_grid	line;

	line = NULL;

	line = (t_2d_grid *)malloc(t_2d_grid);
	if (!line)
		return (NULL);

}


t_2d_grid	*bresenham_algo(int x0,int x1,int y0,int y1, int get_x)
{
	int	dx;
	int	dy;
	int	decision_param;

	dx = x1 - x0;
	dy = y1 - y0;
	decision_param = 2 * dy - dx;
	
}

