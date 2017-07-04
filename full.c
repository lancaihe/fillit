/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:42:39 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/28 00:44:45 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	set_piece(t_etroid *tetroid, t_map *map, t_size *size, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetroid->width)
	{
		j = 0;
		while (j < tetroid->height)
		{
			if (tetroid->pos[j][i] != '.' && tetroid->pos[j][i] != '\n')
				map->array[size->y + j][size->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&size);
}

int		place(t_etroid *tetroid, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetroid->width)
	{
		j = 0;
		while (j < tetroid->height)
		{
			if (tetroid->pos[j][i] == tetroid->curr)
			{
				if (map->array[y + j][x + i] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	set_piece(tetroid, map, size_new(x, y), tetroid->curr);
	return (1);
}

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_etroid	*tetroid;

	if (list == NULL)
		return (1);
	y = 0;
	tetroid = (t_etroid *)(list->content);
	while (y < map->size - tetroid->height + 1)
	{
		x = 0;
		while (x < map->size - tetroid->width + 1)
		{
			if (place(tetroid, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetroid, map, size_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = high_squarert(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		freemap(map);
		map = map_new(size);
	}
	return (map);
}
