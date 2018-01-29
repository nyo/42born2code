/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 23:48:56 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 15:17:43 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	lst_del_head/tail/mid() all are called to remove nodes from the linked list.
**	-------------------------------------------------------------------------- +
*/

void		lst_del_head(t_files **head)
{
	t_files	*save;

	save = *head;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->file_current = TRUE;
		(*head)->prev = NULL;
	}
	ft_strdel(&save->file_name);
	ft_free(save);
}

void		lst_del_middle(t_files *curr)
{
	curr->next->file_current = TRUE;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	ft_strdel(&curr->file_name);
	ft_free(curr);
}

void		lst_del_tail(t_files **head, t_files *curr)
{
	(*head)->file_current = TRUE;
	curr->prev->next = NULL;
	ft_strdel(&curr->file_name);
	ft_free(curr);
}

/*
**	-------------------------------------------------------------------------- +
**	lst_add_bottom() adds a new node to the bottom of the linked list.
**	It returns EXIT_FAILURE on failure, and EXIT_SUCCESS on success.
**	-------------------------------------------------------------------------- +
*/

static int	lst_add_bottom(t_files *head, char *name)
{
	t_files	*new_node;
	t_files	*current;

	current = head;
	if (!(new_node = malloc(sizeof(t_files)))
			|| !(new_node->file_name = ft_strdup(name)))
		return (EXIT_FAILURE);
	new_node->file_selected = FALSE;
	new_node->file_current = FALSE;
	new_node->file_exists = TRUE;
	new_node->file_color = TRUE;
	new_node->next = NULL;
	if (head->next == NULL)
	{
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new_node->prev = current;
		current->next = new_node;
	}
	return (EXIT_SUCCESS);
}

/*
**	-------------------------------------------------------------------------- +
**	lst_init() initializes the linked list.
**	-------------------------------------------------------------------------- +
*/

int			lst_init(t_files **head, char **files)
{
	t_files	*lst;
	int		i;

	i = 1;
	lst = *head;
	if (!(lst = malloc(sizeof(t_files))))
		return (EXIT_FAILURE);
	if (!(lst->file_name = ft_strdup(*(files + i++))))
		return (EXIT_FAILURE);
	lst->file_selected = FALSE;
	lst->file_current = TRUE;
	lst->file_exists = TRUE;
	lst->file_color = TRUE;
	lst->prev = NULL;
	lst->next = NULL;
	while (*(files + i))
	{
		if (lst_add_bottom(lst, *(files + i)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	*head = lst;
	return (EXIT_SUCCESS);
}
