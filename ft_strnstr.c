/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 23:29:48 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/27 18:58:55 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;

	if (*s2 == '\0')
		return ((char *)s1);
	if (!*s1 || !*s2)
		return (NULL);
	i = 0;
	while (*s1 && len > 0)
	{
		if (*s1 == s2[i])
			i++;
		else if (s2[i] != '\0')
		{
			s1 = (s1 - i + 1);
			len = (len - i + 2);
			i = 0;
		}
		if (s2[i] == '\0')
			return ((char *)(s1 - i + 1));
		s1++;
		len--;
	}
	return (NULL);
}
