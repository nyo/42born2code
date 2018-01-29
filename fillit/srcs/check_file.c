/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:43 by anyo              #+#    #+#             */
/*   Updated: 2016/12/06 16:59:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check_file
**
** Definition:	Checks if the file is correct.
**				Checks that there is only # and . and that
**				each tetriminos is a 16 square.
** 		Add in between tetriminos '*' in order to split strings
** 		with ft_strsplit.
**
** Return value: Return table of strings with each full tetriminos.
*/

/*
** check_connection
**
** Checks the connection between diese.
** Add every connection from two diese + the diese it self
** Should arrive at 6 or 8 connections + 4 diese
*/

static int		check_connection(char *s)
{
	int	i;
	int	bloc;
	int	diese;

	i = 0;
	bloc = 0;
	diese = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i < 19 && s[i + 1] == '#')
				bloc++;
			if (i > 0 && s[i - 1] == '#')
				bloc++;
			if (i < 15 && s[i + 5] == '#')
				bloc++;
			if (i > 4 && s[i - 5] == '#')
				bloc++;
			diese++;
		}
		i++;
	}
	bloc = diese == 4 ? bloc : 0;
	return (bloc);
}

/*
** isvalid_tetri
**
** Checks if the string taken is valid as tetriminos
** blocs connection are checked
*/

static int		isvalid_tetri(char *str, size_t i)
{
	size_t		j;
	int			bloc;

	j = 0;
	bloc = 0;
	while (j < 20)
	{
		if (!((j + 1) % 5) && str[i + j] != '\n')
			return (0);
		else if (((j + 1) % 5) && str[i + j] != '.' && str[i + j] != '#')
			return (0);
		j++;
	}
	bloc = check_connection(ft_strsub(str, i, 20));
	if (bloc != 6 && bloc != 8)
		return (0);
	return (1);
}

char			**check_file(char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (len > 26 * 20 + 25)
		return (NULL);
	while (i < len)
	{
		if (!isvalid_tetri(str, i))
			return (NULL);
		i += 20;
		if (str[i] != '\0' && str[i] != '\n')
			return (NULL);
		if (str[i] == '\n')
			str[i] = '*';
		i++;
	}
	if (i == len)
		return (NULL);
	return (ft_strsplit(str, '*'));
}
