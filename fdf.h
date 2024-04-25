/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:23:09 by akloster          #+#    #+#             */
/*   Updated: 2024/03/23 10:23:09 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "/usr/local/include/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

typedef struct  s_data
{
	void        *img;
	char    	*addr;
	int	    	bpp;
	int		    line_length;
	int		    endian;
}               t_data;

typedef struct			s_2d_point
{
	int	x;
	int	y;
}						t_2d_point;

typedef struct			s_2d_grid
{
	t_2d_point			point;
	struct	s_2d_grid	*next;
	struct	s_2d_grid	*under;
}						t_2d_grid;

typedef struct			s_3d_grid
{
	int					x;
	int					y;
	int					z;
	struct	s_3d_grid	*next;
}						t_3d_grid;

typedef struct	s_3x1
{
	float			x;
	float			y;
	float			z;
}				t_3x1;

typedef struct s_3x3
{
	float			x_x;
	float			x_y;
	float			x_z;
	float			y_x;
	float			y_y;
	float			y_z;
	float			z_x;
	float			z_y;
	float			z_z;
}				t_3x3;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_3d_grid	*create_3d_grid(int fd);
t_2d_grid	*create_2d_grid(t_3d_grid *head_3d);
void		grid_3d_lstclear(t_3d_grid **lst);
void		grid_2d_lstclear(t_2d_grid **lst);
void		free_ptr_array(char ***s);
int			draw_line(t_2d_point i, t_2d_point f, t_data *img);
void    	put_circle(int r, int x, int y, t_data *img);  				// <---- TEST (delete!)
void		put_square(int a, int center_x, int center_y, t_data *img); // <---- TEST (delete!)
/* void		calibrate(t_2d_grid	*head); */
int			abs(int nbr);
int			matrix_calc(t_3d_grid *point_3d, int x);
void		set_1st_quad(t_2d_grid *head);

#endif
