/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:21:09 by anyo              #+#    #+#             */
/*   Updated: 2017/01/19 23:17:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_check() prints an bold-italic-yellow "CHECK!".
**	Useful when debugging code.
*/

void	ft_check(void)
{
	ft_putstr("\x1b[1;3;33mCHECK!\x1b[0m\n");
}
