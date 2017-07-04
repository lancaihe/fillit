/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 11:01:28 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 15:34:12 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list*elem))
{
	t_list	*cursor;

	cursor = lst;
	if (lst != NULL || f != NULL)
	{
		while (cursor)
		{
			(*f)(cursor);
			cursor = cursor->next;
		}
	}
}
