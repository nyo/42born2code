/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:31:39 by anyo              #+#    #+#             */
/*   Updated: 2016/08/25 23:37:03 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	**begin_list;

	i = 0;
	list = ft_create_elem(argv[i]);
	if (list)
	{
		while (i < argc)
		{
			list = ft_create_elem(argv[i]);
			list->next = list;
			*begin_list = list;
			i += 1;
		}
	}
	return (list);
}
