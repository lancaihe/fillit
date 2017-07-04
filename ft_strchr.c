/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:01:37 by pmoran            #+#    #+#             */
/*   Updated: 2016/10/20 03:14:55 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strchr(const char *s, int c)
{
	char d;

	d = (char)c;
	while ((char)*s != d && (char)*s != 0)
		s++;
	if ((char)*s == d)
		return (s);
	if (d == 0)
		return (s++);
	else
		return (NULL);
}
