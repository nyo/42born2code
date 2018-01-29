/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:58:00 by anyo              #+#    #+#             */
/*   Updated: 2017/06/08 20:58:19 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	arg_len() returns the lenght of `t_arg` linked list.
**	return value:
**		The lenght - OK!
*/

int	arg_len(t_arg *arg)
{
	int	len;

	len = 0;
	while (arg)
	{
		len++;
		arg = arg->next;
	}
	return (len);
}
