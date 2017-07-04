/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:37:58 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/10 16:23:33 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		isfirst(const char *s, int c)
{
	if (*s == c)
		return (1);
	return (0);
}

const char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;
	int		firsty;

	firsty = isfirst(s, c);
	i = 0;
	d = (char)c;
	if (*s == 0 && d == 0)
		return (s);
	while (*s != 0)
	{
		s++;
		i++;
	}
	while (i > 0)
	{
		i--;
		if (*s == d)
			return (s);
		s--;
	}
	if (firsty)
		return (s);
	return (NULL);
}
