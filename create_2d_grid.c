#include "fdf.h"

t_2d_grid	*create_2d_grid(t_3d_grid *head_3d)
{
	t_2d_grid	*head;
	t_2d_grid	*temp;
	t_3d_grid	*temp_3d;

	temp_3d = head_3d;
	head = NULL;
	head = create_2d_point(head, temp_3d)
	if (!head)
		return (1);
	while (temp_3d != NULL)
	{
		temp = create_2d_point(head, temp_3d);
		if
	}
