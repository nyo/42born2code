/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:03:44 by anyo              #+#    #+#             */
/*   Updated: 2018/01/29 18:06:20 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	man 3 getch
**	-------------------------------------------------------------------------- +
*/

int	ft_getch(void)
{
	char	ch;
	int		ret;

	if ((ret = read(STDIN_FILENO, &ch, 1)) == -1)
		return (-1);
	return (ch);
}
