/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:24:07 by anyo              #+#    #+#             */
/*   Updated: 2017/11/30 16:55:25 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	Outputs the string `s` to the file descriptor `fd`.
**	-------------------------------------------------------------------------- +
*/

void	ft_putstr_fd(char const *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}
