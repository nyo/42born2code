/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:40:23 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/06 15:06:51 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Gets tetri's width and stores it into the struct
*/

static void		get_piece_width(t_piece *piece)
{
	int		i;
	int		width;
	BITS	curr_bit;

	i = 0;
	while (i < piece->height)
	{
		width = 4;
		curr_bit = piece->bits[i];
		while (curr_bit % 2 == 0)
		{
			curr_bit /= 2;
			width--;
		}
		piece->width = width > piece->width ? width : piece->width;
		i++;
	}
}

/*
** To comment!
*/

static void		trim_bits(t_piece *piece)
{
	int		i;
	int		test;

	i = 0;
	test = piece->height;
	while (i < piece->height)
		test = piece->bits[i++] < 8 ? test - 1 : test;
	i = 0;
	if (!test)
	{
		while (i < piece->height)
			piece->bits[i++] <<= 1;
		trim_bits(piece);
	}
	else
	{
		get_piece_width(piece);
		while (i < piece->height)
			piece->bits[i++] <<= 12;
	}
}

/*
** Fills struct's bits with the "tetri binary value"
*/

static void		get_piece(char *str, t_piece *piece)
{
	int		i;
	int		width;

	i = 0;
	piece->bits = (BITS*)malloc(sizeof(BITS) * (piece->height));
	while (*str)
	{
		width = 0;
		piece->bits[i] = 0;
		while (*str && *str != '\n')
		{
			piece->bits[i] <<= 1;
			if (*str == '#')
				piece->bits[i] += 1;
			str++;
		}
		i++;
		str++;
	}
}

/*
** Turns the bits array into a string
*/

static char		*ft_make_str(BITS *bits, int height)
{
	int		i;
	int		j;
	BITS	curr_bit;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * (height * 5));
	while (i < height)
	{
		j = 0;
		curr_bit = bits[i] >> 12;
		while (j < 4)
		{
			s[3 - j + i * 5] = curr_bit % 2 ? '#' : '.';
			curr_bit >>= 1;
			j++;
		}
		s[j + i * 5] = (i + 1) == height ? '\0' : '\n';
		i++;
	}
	return (s);
}

/*
** Initializes a new tetri
*/

t_piece			*new_piece(char name, char *str)
{
	t_piece		*new;
	int			len;

	new = (t_piece*)malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(new->bits || new->str))
		return (NULL);
	new->name = name;
	new->x = 0;
	new->y = 0;
	str = trim_str(str);
	len = ft_strlen(str);
	new->height = len / 4 > 4 ? 4 : len / 4;
	get_piece(str, new);
	trim_bits(new);
	new->str = ft_make_str(new->bits, new->height);
	new->next = NULL;
	return (new);
}
