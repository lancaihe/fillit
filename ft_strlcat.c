/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:43:48 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/10 16:55:13 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t		ft_strlen(char const *str)
{
	size_t i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < size - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < size)
		dst[i] = '\0';
	return (s1_end + ft_strlen(src));
}
