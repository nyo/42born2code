/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:52:05 by anyo              #+#    #+#             */
/*   Updated: 2017/01/19 23:29:14 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_itc() searchs for the given character in the given string.
**	It returns the character position in the string, as an int,
**	or -1 if the character wasn't not found.
*/

int		ft_itc(char *str, char c)
{
	int	i;

	i = -1;
	if (*str)
		while (*(str + ++i))
			if (*(str + i) == c)
				return (i);
	return (-1);
}
