/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:28:01 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 21:44:53 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstreverse(t_list **alst)
{
	t_list	*prev;
	t_list	*swap;
	t_list	*next;

	prev = NULL;
	swap = *alst;
	while (swap != NULL)
	{
		next = swap->next;
		swap->next = prev;
		prev = swap;
		swap = next;
	}
	*alst = prev;
}
