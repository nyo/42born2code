/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:17:33 by anyo              #+#    #+#             */
/*   Updated: 2016/11/15 22:20:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordilen(char const *s, char c, int index)
{
	int	len;

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
	while (*s != c)
	{
		s++;
		len++;
	}
	return (len);
}
