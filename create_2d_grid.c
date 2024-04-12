#include "fdf.h"

static float	matrix_calc(t_3d_grid *point_3d, int x)
{
	t_3x3	rotation_matrix;
	t_3x1	a;
	t_3x1	b;

	//assign these values once in fdf.h or assign once in main
	rotation_matrix.x_x = sqrt(3) / sqrt(6);
	rotation_matrix.x_y = 0;
	rotation_matrix.x_z = -(sqrt(3)) / sqrt(6);
	rotation_matrix.y_x = 1 / sqrt(6);
	rotation_matrix.y_y = 2 / sqrt(6);
	rotation_matrix.y_z = 1 / sqrt(6);
	rotation_matrix.z_x = sqrt(2) / sqrt(6);
	rotation_matrix.z_y = -(sqrt(2)) / sqrt(6);
	rotation_matrix.z_z = sqrt(2) / sqrt(6);
	a.x = point_3d->x;
	a.y = point_3d->y;
	a.z = point_3d->z;
	b.x = rotation_matrix.x_x * a.x + rotation_matrix.x_y * a.y + rotation_atrix.x_z * a.z; 
	b.y = rotation_matrix.y_x * a.x + rotation_matrix.y_y * a.y + rotation_atrix.y_z * a.z; 
	if (x)
		return (b.x);
	return (b.y);
}



static	t_2d_grid	*create_2d_point(t_2d_grid *head, t_3d_grid *temp)
{
	t_2d_grid	*new_point;
	t_2d_grid	*temp;

	new_point = (t_2d_grid *)malloc(sizeof(t_2d_grid));
	if (!new_point)
		return (NULL);
	new_point->x = matrix_calc(temp, 1);
	new_point->y = matrix_calc(temp, 0);
	new_point->next = NULL;
	if (!head)
		head = new_point;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_point;
	}
	return (head);
}

t_2d_grid	*create_2d_grid(t_3d_grid *head_3d)
{
	t_2d_grid	*head;
	t_2d_grid	*temp;
	t_3d_grid	*temp_3d;

	temp_3d = head_3d;
	head = NULL;
	head = create_2d_point(head, temp_3d)
	if (!head)
		return (grid_lstclear(&head_3d), NULL);
	while (temp_3d != NULL)
	{
		temp = create_2d_point(head, temp_3d);
		if (!temp)
			return (grid_lstclear(&head_3d, &head), NULL);
	}
	// is 3d_grid still needed -- look for free point
	return (head);
}
