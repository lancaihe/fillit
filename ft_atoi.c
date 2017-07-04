/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:34:56 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/10 15:11:39 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int num;

	sign = 0;
	num = 0;
	i = 0;
	if (!str[0] || !str)
		return (0);
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (((str[i] == '+' && str[i + 1] > 47 && str[i + 1] < 58)) \
			|| (str[i] > 47 && str[i] < 58))
		sign = 1;
	if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while ((str[i] > 47 && str[i] < 58))
		num = num * 10 + (str[i++] - 48);
	return (sign * num);
}
