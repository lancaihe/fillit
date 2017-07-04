/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:36:46 by pmoran            #+#    #+#             */
/*   Updated: 2016/10/11 18:21:50 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if ((unsigned char)*s1 < (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
