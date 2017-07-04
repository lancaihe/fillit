/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_and_pass_tetras.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:24:55 by pkreitz           #+#    #+#             */
/*   Updated: 2016/11/28 00:47:09 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_fillit_strtrim(char *str)
{
	int		i;
	int		l;
	char	*str2;

	l = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] != 'x')
			l++;
	}
	if ((str2 = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] != 'x' && (str[i + 1] != '\0'))
			str2[l++] = str[i];
		i++;
	}
	if (str2[l - 1] == '\n')
		str2[l - 1] = '\0';
	str2[l] = '\0';
	return (str2);
}

int			ft_tetracmp(char *str, char **nineteen_tetras)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 19)
	{
		if ((ft_strcmp(str, nineteen_tetras[i])) == 0)
			j = 1;
		i++;
	}
	if (j != 1)
		return (1);
	return (0);
}

char		*ft_poundtoalpha(char *str, int i)
{
	int		a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '#')
			str[a] = ('A' + i);
		a++;
	}
	return (str);
}

int			throw_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

char		**check_and_pass_tetras(char **str, char **nineteen_tetras)
{
	int		i;
	char	**str2;

	i = 0;
	i = ft_strlen(str[i]);
	str2 = (char **)malloc((sizeof(char *)) * i + 1);
	str2[i + 1] = 0;
	i = 0;
	while (str[i])
	{
		valid_and_crop(str, i);
		str[i] = ft_fillit_strtrim(str[i]);
		if (ft_tetracmp(str[i], nineteen_tetras))
			throw_error();
		str[i] = ft_poundtoalpha(str[i], i);
		str2[i] = ft_strdup(str[i]);
		i++;
	}
	if (i > 26)
		throw_error();
	return (str2);
}
