/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:33:17 by anyo              #+#    #+#             */
/*   Updated: 2016/12/06 17:02:34 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** trim_str trims the string received to have the piece
** the most up before conversion to binary. Gives us the height.
*/

char	*trim_str(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strdup(str);
	while (s[i] == '.' || s[i] == '\n')
	{
		if (s[++i] == '\n')
		{
			s += i + 1;
			i = 0;
		}
	}
	ft_strrev(s);
	i = 0;
	while (s[i] == '.' || s[i] == '\n')
	{
		if (s[++i] == '\n')
		{
			s += i + 1;
			i = 0;
		}
	}
	return (ft_strrev(s));
}
