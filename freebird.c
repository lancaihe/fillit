/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freebird.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:59:51 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 21:44:19 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*free_list(t_list *list)
{
	t_etroid	*tetroid;
	t_list		*next;

	while (list)
	{
		tetroid = (t_etroid *)list->content;
		next = list->next;
		free_tetroid(tetroid);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void			free_tetroid(t_etroid *tetroid)
{
	int y;

	y = 0;
	while (y < tetroid->height)
	{
		ft_memdel((void **)(&(tetroid->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetroid->pos)));
	ft_memdel((void **)&tetroid);
}

t_etroid		*tetroid_new(char **pos, int width, int height, char curr)
{
	t_etroid	*tetroid;

	tetroid = ft_memalloc(sizeof(t_etroid));
	tetroid->pos = pos;
	tetroid->width = width;
	tetroid->height = height;
	tetroid->curr = curr;
	return (tetroid);
}

t_size			*size_new(int x, int y)
{
	t_size		*size;

	size = ft_memalloc(sizeof(t_size));
	size->x = x;
	size->y = y;
	return (size);
}

void			freemap(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&map);
	return ;
}
