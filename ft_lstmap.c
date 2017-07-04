/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:26:43 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 17:29:31 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*tmpresult;
	t_list	*tmplst;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmplst = f(lst);
	if ((result = ft_lstnew(tmplst->content, tmplst->content_size)))
	{
		tmpresult = result;
		lst = lst->next;
		while (lst != NULL)
		{
			tmplst = (*f)(lst);
			if (!(tmpresult->next = ft_lstnew(tmplst->content,
							tmplst->content_size)))
				return (NULL);
			tmpresult = tmpresult->next;
			lst = lst->next;
		}
	}
	return (result);
}
