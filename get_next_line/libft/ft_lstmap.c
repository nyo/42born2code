/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:23:26 by anyo              #+#    #+#             */
/*   Updated: 2017/01/19 23:07:54 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!lst)
		return (NULL);
	ptr2 = f(lst);
	ptr1 = ptr2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr2->next = f(lst)))
		{
			free(ptr2->next);
			return (NULL);
		}
		ptr2 = ptr2->next;
	}
	return (ptr1);
}
