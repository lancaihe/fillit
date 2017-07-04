/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:44:23 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/26 13:01:25 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd((char *)str, fd);
	ft_putchar_fd('\n', fd);
	return ;
}
