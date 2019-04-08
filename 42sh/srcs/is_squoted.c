/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_squoted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:48:24 by anyo              #+#    #+#             */
/*   Updated: 2018/04/20 22:17:06 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
**	-------------------------------------------------------------------------- +
**	Takes a string and an index, and tells if string[0:index] is single quoted.
**	-------------------------------------------------------------------------- +
*/

int	is_squoted(char *input, int index)
{
	int	i;

	i = 0;
	while (input[i] && i < index)
	{
		if (input[i] == CH_SQUOTE && (i == 0 || input[i - 1] != CH_BACKSLASH))
		{
			i++;
			while (input[i] && input[i] != CH_SQUOTE && i < index)
				i++;
			if (!input[i] || input[i] != CH_SQUOTE)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
