/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:44 by akloster          #+#    #+#             */
/*   Updated: 2024/04/04 18:53:23 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid_lstclear(t_3d_grid **lst)
{
	t_3d_grid	*temp;
	t_3d_grid	*prev;

	if (!lst || !(*lst))
		return ;
	temp = *lst;
	*lst = NULL;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*lst = NULL;
}

void	free_ptr_array(char ***s)
{
	int	i;

	if (!**s || !*s)
		return ;
	i = 0;
	if (*s != NULL)
	{
		while ((*s)[i] != NULL)
		{
			free((*s)[i]);
			(*s)[i] = NULL;
			++i;
		}
		free(*s);
		*s = NULL;
	}
}