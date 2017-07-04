/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:00:37 by pmoran            #+#    #+#             */
/*   Updated: 2016/10/27 08:49:27 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	if (!*s2)
		return (s1);
	if (!*s1 && *s2)
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (*s1 == s2[i])
			i++;
		else if (s2[i++] != '\0')
		{
			s1 = (s1 - i + 1);
			i = 0;
		}
		if (s2[i] == '\0')
			return (s1 - i + 1);
		s1++;
	}
	return (NULL);
}
