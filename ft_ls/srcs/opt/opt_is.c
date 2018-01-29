/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:26:23 by anyo              #+#    #+#             */
/*   Updated: 2017/05/16 16:56:19 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	opt_is() indicates if a string is an option, valid or not.
**	return value:
**		0 - not an option
**		1 - valid option
**		2 - invalid option
*/

int			opt_is(char *opt)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(opt);
	if (*opt == '-' && len > 1)
	{
		while (len > ++i)
			if (!(ISVLDLTR(*(opt + i))))
				break ;
		return (len == i ? 1 : 2);
	}
	return (0);
}
