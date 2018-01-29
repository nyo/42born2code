/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 09:50:48 by anyo              #+#    #+#             */
/*   Updated: 2016/08/23 09:50:58 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
