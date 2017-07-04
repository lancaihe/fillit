/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:43:22 by pmoran            #+#    #+#             */
/*   Updated: 2016/10/27 09:12:26 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char		*ft_strdup(char *s)
{
	int		str_length;
	char	*copy_to;
	int		i;

	str_length = ft_strlen(s);
	copy_to = (char*)malloc((str_length + 1) * sizeof(char));
	if (!copy_to)
		return (NULL);
	i = 0;
	while (i < str_length)
	{
		copy_to[i] = s[i];
		i++;
	}
	copy_to[i] = '\0';
	return (copy_to);
}
