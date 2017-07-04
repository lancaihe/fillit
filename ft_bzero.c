/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:31:22 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 20:44:28 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *b, size_t len)
{
	unsigned char *cur;

	if (len == 0)
		return ;
	cur = (unsigned char *)b;
	while (len--)
	{
		*cur = (unsigned char)0;
		if (len)
			cur++;
	}
	return ;
}
