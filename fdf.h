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

typedef struct			s_2d_grid
{
	int					x;
	int					y;
	struct	s_2d_grid	*next;
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
	int			x;
	int			y;
	int			z;
}				t_3x1;

typedef struct s_3x3
{
	int			x_x;
	int			x_y;
	int			x_z;
	int			y_x;
	int			y_y;
	int			y_z;
	int			z_x;
	int			z_y;
	int			z_z;
}				t_3x3;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_3d_grid	*create_3d_grid(int fd, t_3d_grid **head);
void		ft_fdf_lstclear(t_3d_grid **lst);
void	free_ptr_array(char ***s);

void    put_circle(int r, int x, int y, t_data *img);  				// <---- TEST (delete!)
void    put_square(int a, int center_x, int center_y, t_data *img); // <---- TEST (delete!)

#endif
