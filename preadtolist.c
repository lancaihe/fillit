/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preadtolist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 22:02:06 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 22:25:04 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void		printmap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->array[i]);
		i++;
	}
	return ;
}

int			high_squarert(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void		sizer(char *str, t_size *size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (str[i] != 0)
	{
		x = 0;
		while (str[i] != '\n' && str[i] != 0)
		{
			i++;
			x++;
		}
		if (size->x < x)
			size->x = x;
		y++;
		i++;
	}
	size->y = y;
	return ;
}

t_etroid	*get_piece(char *str, char curr)
{
	t_size		*size;
	char		**pos;
	t_etroid	*tetroid;

	size = size_new(0, 0);
	sizer(str, size);
	pos = ft_strsplit(str, '\n');
	tetroid = tetroid_new(pos, size->x, size->y, curr);
	ft_memdel((void **)&size);
	return (tetroid);
}

t_list		*readin(char **str)
{
	int			i;
	int			j;
	t_list		*list;
	t_etroid	*tetroid;
	char		curr;

	i = 0;
	list = NULL;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] == '.')
			j++;
		curr = str[i][j];
		tetroid = get_piece(str[i], curr);
		ft_memdel((void **)&str[i]);
		ft_lstadd(&list, ft_lstnew(tetroid, sizeof(t_etroid)));
		ft_memdel((void **)&tetroid);
		i++;
	}
	ft_memdel((void **)&str[i - 1]);
	ft_lstreverse(&list);
	return (list);
}
