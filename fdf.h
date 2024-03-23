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

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct  s_data
{
	void        *img;
	char    	*addr;
	int	    	bits_per_pixel;
	int		    line_length;
	int		    endian;
}               t_data;


#endif
