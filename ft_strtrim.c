/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:21:09 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/10 16:51:10 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_end(char *str, int i)
{
	while (str[i] != 0)
		i++;
	if (str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t')
	{
		i--;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i--;
		i++;
	}
	else
		return (i + 1);
	return (i);
}

char		*ft_strtrim(char const *str)
{
	int		i;
	int		len;
	int		end;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != 0)
		i++;
	len = i;
	new = (char *)malloc((sizeof(char) * (len + 1)));
	if (!new)
		return (NULL);
	len = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	end = ft_end((char *)str, i);
	while (end > i)
		new[len++] = str[i++];
	new[len] = '\0';
	return ((char *)new);
}
