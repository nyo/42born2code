/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:23:26 by anyo              #+#    #+#             */
/*   Updated: 2016/11/16 20:43:11 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newmaptmp;
	t_list	*newmap;

	newmap = NULL;
	newmaptmp = NULL;
	if ((newmap = (t_list *)malloc(ft_lstlen(lst) * sizeof(t_list))))
	{
		newmap = f(ft_lstnew(lst->content, lst->content_size));
		newmaptmp = newmap;
		lst = lst->next;
		while (lst)
		{
			newmaptmp->next = f(ft_lstnew(lst->content, lst->content_size));
			newmaptmp = newmaptmp->next;
			lst = lst->next;
		}
	}
	return (newmap);
}
