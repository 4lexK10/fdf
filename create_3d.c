/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:03:22 by akloster          #+#    #+#             */
/*   Updated: 2024/05/05 20:28:48 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*clean_line(char *str);
static char	*simplify(char **raw_line);

int	*create_3d(fd)
{
	char	*raw;
	char	**raw_line;
	char	*map_3d;
	int		size;

	size = 0;
	raw = clean_line(get_next_line(fd));
	raw_line = ft_split(raw, ' ');
	while (raw_line[size] != NULL)
		++size;
	map_3d = simplify(raw_line, size);
}

static char	*simplify(char **raw_line, int size)
{
	char	*buf;
	int		i;
	int		*line;

	line = (int)malloc(sizeof(int) * size);
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
