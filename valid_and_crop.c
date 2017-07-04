/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_crop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:25:42 by pkreitz           #+#    #+#             */
/*   Updated: 2016/11/28 00:37:13 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			ft_ismapvalidp1(char *str)
{
	int		pound;
	int		period;
	int		i;

	period = 0;
	pound = 0;
	i = 0;
	while (i != 21)
	{
		if (str[i] == '#')
			pound++;
		if (str[i] == '.')
			period++;
		i++;
	}
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n'
			|| pound != 4 || period != 12)
		return (1);
	return (0);
}

char		*ft_crop_tetra_p1(char *str)
{
	int		i;
	int		period_count;

	i = 0;
	period_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			period_count = 0;
		if (str[i] == '.')
			period_count++;
		if (period_count == 4)
		{
			while (str[i - 1] == '.')
				i--;
			while (str[i] != '\n')
				str[i++] = 'x';
			str[i] = 'x';
			period_count = 0;
		}
		i++;
	}
	str[20] = 'x';
	return (str);
}

void		p2_while_loop(int i, int end_mark, int start_mark, char *str)
{
	int		period_count;

	period_count = 0;
	while (i <= end_mark)
	{
		if (str[i] == '.' || str[i] == 'x')
			period_count++;
		if (period_count == 4)
		{
			while (i != start_mark)
				i = (i - 5);
			while (i <= end_mark)
			{
				str[i] = 'x';
				i = i + 5;
			}
		}
		i = i + 5;
	}
	i = start_mark + 1;
}

char		*ft_crop_tetra_p2(char *str)
{
	int		i;
	int		end_mark;
	int		start_mark;
	int		period_count;

	i = 0;
	while (i != 4)
	{
		period_count = 0;
		start_mark = i;
		end_mark = (i + 15);
		p2_while_loop(i, end_mark, start_mark, str);
		i = start_mark + 1;
	}
	return (str);
}

char		*valid_and_crop(char **str, int i)
{
	if (ft_ismapvalidp1(str[i]) == 1)
		throw_error();
	connect_count(str[i]);
	ft_crop_tetra_p1(str[i]);
	ft_crop_tetra_p2(str[i]);
	return (str[i]);
}
