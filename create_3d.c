/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:03:22 by akloster          #+#    #+#             */
/*   Updated: 2024/05/01 19:28:29 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*clean_line(char *str);
static char	*simplify(char **raw_line);

int	*create_3d(fd)
{
	char	*raw;
	char	**line;
	char	*map_3d;
	

	raw = clean_line(get_next_line(fd));
	line = ft_split(raw, ' ');
	map_3d = simplify(line);
}

static char	*simplify(char **raw_line)
{
	char	*simp;
	char	*buf;
	int		i;

	simp = ft_strdup(raw_line[0])
	while (raw_line[i] != NULL)
	{
		
	}
}

static char *clean_line(char *str)
{
	char *line;

	line = ft_strtrim(str, "\n");
	free(str);
	if (!line)
		return (NULL);
	return (line);
}
