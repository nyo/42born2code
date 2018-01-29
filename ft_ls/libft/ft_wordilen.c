/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:17:33 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:18:34 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_wordilen() returns the lenght of the word at the index 'index'.
**	'c' is the character between words.
*/

size_t	ft_wordilen(char const *s, char c, int index)
{
	size_t	len;

	len = 0;
	while (*s == c)
		s++;
	while (index > 0)
	{
		while (*s != c)
			s++;
		while (*s == c)
			s++;
		index--;
	}
	while (*s++ != c)
		len++;
	return (len);
}
