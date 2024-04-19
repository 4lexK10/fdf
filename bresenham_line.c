#include "fdf.h"

static int	swap_coordinates(int *x0,int *x1,int *y0,int *y1)
{
	int	temp;

	temp = *x0;
	*x0 = *y0;
	*y0 = temp;
	temp = *x1;
	*x1 = *y1;
	*y1 = temp;
	return (1);
}

int	bresenham_algo(int x0,int x1,int y0,int y1)
{
	int	dx;
	int	dy;
	int	decision_param;
	int	x;
	int y;

	x = x0;
	y = x1;
	if (y1 > y0)
		decision_param = swap_coordinates(&x0, &x1, &y0, &y1);
	dx = x1 - x0;
	dy = y1 - y0;
	decision_param = 2 * dy - dx;
	while (x <= x1)
	{
		//put_pixell();
		if (decision_param < 0)
			decision_param += 2 * dy;
		else
		{
			decision_param += 2 * dy - 2 * dx;
			++y; 
		}
		++x;
	}
	return (0);
}
