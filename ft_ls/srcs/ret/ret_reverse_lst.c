/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_reverse_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:18:25 by anyo              #+#    #+#             */
/*   Updated: 2017/06/01 19:36:52 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_reverse_lst() reverses the linked list `t_ret`,
**	so it gets printed in the right order later.
*/

void	ret_reverse_lst(t_ret **ret)
{
	t_ret	*prev;
	t_ret	*next;
	t_ret	*current;

	prev = NULL;
	current = *ret;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*ret = prev;
	free(next);
	free(current);
}
