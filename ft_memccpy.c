/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:55:35 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/10 15:46:06 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	ruc;

	if (n == 0 || dest == src)
		return (NULL);
	ruc = 0;
	c1 = (char *)dest;
	c2 = (char *)src;
	while (ruc < n)
	{
		c1[ruc] = c2[ruc];
		if (c1[ruc] == c)
			return (c1 + ruc + 1);
		ruc++;
	}
	return (NULL);
}
