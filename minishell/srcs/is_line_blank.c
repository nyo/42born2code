/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_blank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 18:09:00 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 22:20:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	macro_check() goes through every single character of the given string,
**	and checks if they all are hidden characters.
**	return value:
**	0	-	the string does not contain only hidden characters
**	1	-	the string contains only hidden characters
*/

static int	macro_check(char *line)
{
	int	i;
	int	nobc;

	i = 0;
	nobc = 0;
	while (*(line + i))
	{
		if (ISBLANK(*(line + i)) == 1)
			nobc++;
		i++;
	}
	return (nobc == i ? 1 : 0);
}

/*
**	is_line_blank() checks if the given string contains
**	stuff we want to work with.
**	return value:
** 	+ add: check for ANSI escape sequences
**	0	-	the string isn't blank
**	1	-	the string is blank
*/

int			is_line_blank(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0 || macro_check(line) == 1)
		return (1);
	return (0);
}
