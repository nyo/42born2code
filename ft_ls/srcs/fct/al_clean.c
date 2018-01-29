/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 00:05:19 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 22:34:08 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	al_clean() returns a copy of `char **argv`, without the options
**	entered as parameters.
**	return value:
**		NULL - ERROR! malloc()
**		The copy, an array of strins - no more data to add, OK!
*/

char	**al_clean(int argc, char **argv)
{
	char	**arglst;
	int		i;
	int		j;

	i = 1;
	j = 0;
	arglst = NULL;
	while (i < argc && opt_is(*(argv + i)))
		i++;
	if (!(arglst = malloc(sizeof(char *) * (argc - i + 1))))
		return (NULL);
	while (i < argc)
		if (!(*(arglst + j++) = ft_strdup(*(argv + i++))))
			return (NULL);
	*(arglst + j) = NULL;
	return (arglst);
}
