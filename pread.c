/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 23:49:15 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/28 00:41:57 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft.h"

char		*ft_maplen(char *str, int fd, char *buf)
{
	int		ret;
	int		k;

	str = NULL;
	k = 0;
	if (fd == -1)
		throw_error();
	while (1)
	{
		ret = read(fd, buf, 21);
		k = k + ret;
		if (ret < 20)
			break ;
	}
	if (!(k % 21) || (ret > 0 && ret < 20))
		throw_error();
	str = (char *)malloc(sizeof(char) * k);
	close(fd);
	return (str);
}

char		**ft_bufstrcpy(char **argv)
{
	char	buf[21];
	char	*str;
	int		fd;
	int		i;
	int		j;

	fd = open(argv[1], O_RDWR);
	i = 0;
	str = ft_maplen(str, fd, buf);
	fd = open(argv[1], O_RDWR);
	while ((read(fd, buf, 21)) > 0)
	{
		j = 0;
		buf[20] = '\0';
		while (buf[j])
			str[i++] = buf[j++];
		str[i++] = '@';
	}
	if (!i)
		throw_error();
	close(fd);
	str[i] = '\0';
	return (ft_strsplit(str, '@'));
}

char		**readtostr_and_tetrasforcmp(char **argv)
{
	char	**str;
	char	**nineteen_tetras;
	char	**str2;
	int		i;

	i = 0;
	str = ft_bufstrcpy(argv);
	nineteen_tetras = (char **)malloc(sizeof(char *) * 19);
	while (i < 19)
		nineteen_tetras[i++] = (char *)malloc((sizeof(char *) * 10));
	nineteen_tetras = nineteen(nineteen_tetras);
	str2 = check_and_pass_tetras(str, nineteen_tetras);
	return (str2);
}

int			main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;
	char	**str;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	str = readtostr_and_tetrasforcmp(argv);
	list = readin(str);
	map = solve(list);
	printmap(map);
	freemap(map);
	free_list(list);
	return (0);
}
