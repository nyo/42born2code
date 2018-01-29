/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:06 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/06 16:18:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Init map creates a map with 32 bits on each row
**  over 32 rows (max number of pieces we can get)
*/

BITS	*init_map(void)
{
	int		i;
	BITS	*map;

	i = 0;
	map = (BITS*)malloc(sizeof(BITS) * 32);
	if (!map)
		return (NULL);
	while (i < 32)
	{
		map[i] = 0x00000000;
		i++;
	}
	return (map);
}
