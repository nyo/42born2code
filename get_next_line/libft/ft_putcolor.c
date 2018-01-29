/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 19:55:34 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:04:09 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_putcolor() prints a colored string.
**		usage:
**			ft_putcolor(STRING, "COLOR");
*/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	ft_putcolor(char const *s, char const *color)
{
	if (!s)
		return ;
	if (!(ft_strcmp(color, "RED")))
		ft_putstr(ANSI_COLOR_RED);
	if (!(ft_strcmp(color, "GREEN")))
		ft_putstr(ANSI_COLOR_GREEN);
	if (!(ft_strcmp(color, "BLUE")))
		ft_putstr(ANSI_COLOR_BLUE);
	if (!(ft_strcmp(color, "YELLOW")))
		ft_putstr(ANSI_COLOR_YELLOW);
	if (!(ft_strcmp(color, "MAGENTA")))
		ft_putstr(ANSI_COLOR_MAGENTA);
	ft_putstr(s);
	ft_putstr(ANSI_COLOR_RESET);
}
