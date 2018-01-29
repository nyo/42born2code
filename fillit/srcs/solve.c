/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:05:57 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/04 17:50:05 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Check piece, checks where can we place the tetri
*/

static BITS		*map_xor_piece(BITS *map, t_piece *piece)
{
	int		i;

	i = -1;
	while (++i < piece->height)
		*(map + piece->y + i) ^= (piece->bits[i] >> piece->x);
	return (map);
}

/*
**	Because 25 lines isn't enough...
*/

static int		just4thenorm(BITS *map, t_piece *piece)
{
	int		i;
	int		res;

	res = 0;
	i = -1;
	while (++i < piece->height)
		res += *(map + piece->y + i) & (piece->bits[i] >> piece->x);
	return (res);
}

/*
**	Checks if the piece can be placed, and retry until every pieces are
*/

BITS			isplace_piece(BITS *map, t_piece *piece, int size)
{
	int		res;

	if (!piece)
		return (1);
	while (piece->y < size - piece->height + 1)
	{
		while (piece->x < size - piece->width + 1)
		{
			res = just4thenorm(map, piece);
			if (!res)
			{
				map_xor_piece(map, piece);
				if (isplace_piece(map, piece->next, size))
					return (1);
				map_xor_piece(map, piece);
			}
			piece->x++;
		}
		piece->x = 0;
		piece->y++;
	}
	piece->y = 0;
	return (0);
}
