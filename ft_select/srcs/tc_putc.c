/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:31:32 by anyo              #+#    #+#             */
/*   Updated: 2017/09/19 17:54:06 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	tc_putc() is a putchar-like routine to which the characters are passed,
**	one at a time, and is here to work with tputs(3).
**	It prints the passed byte, then returns the return value of write() call.
**	-------------------------------------------------------------------------- +
*/

int	tc_putc(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}
