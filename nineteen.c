/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nineteen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 23:51:16 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/27 23:52:22 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**nineteen(char **nineteent)
{
	nineteent[0] = "#.\n#.\n##";
	nineteent[1] = "###\n#..";
	nineteent[2] = "##\n.#\n.#";
	nineteent[3] = "..#\n###";
	nineteent[4] = ".#\n.#\n##";
	nineteent[5] = "#..\n###";
	nineteent[6] = "##\n#.\n#.";
	nineteent[7] = "###\n..#";
	nineteent[8] = "##\n##";
	nineteent[9] = "#\n#\n#\n#";
	nineteent[10] = "####";
	nineteent[11] = "##.\n.##";
	nineteent[12] = ".#\n##\n#.";
	nineteent[13] = ".##\n##.";
	nineteent[14] = "#.\n##\n.#";
	nineteent[15] = "###\n.#.";
	nineteent[16] = ".#\n##\n.#";
	nineteent[17] = ".#.\n###";
	nineteent[18] = "#.\n##\n#.";
	nineteent[19] = NULL;
	return (nineteent);
}
