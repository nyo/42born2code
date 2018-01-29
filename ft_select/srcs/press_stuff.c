/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 23:59:29 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 15:14:37 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	press_arrow_down() sets the file next to the current file, as the current
**	file.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_arrow_down(t_files **head, char *key)
{
	t_files	*curr;

	if (ft_memcmp(key, KEY_DOWN, ft_strlen(key)) == 0
			|| ft_memcmp(key, KEY_RIGHT, ft_strlen(key)) == 0)
	{
		if (!(curr = get_current_file(head)))
			return (-1);
		curr->file_current = FALSE;
		if (curr->next)
			curr->next->file_current = TRUE;
		else
			(*head)->file_current = TRUE;
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_arrow_up() sets the file before the current file, as the current
**	file.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_arrow_up(t_files **head, char *key)
{
	t_files	*curr;

	if (ft_memcmp(key, KEY_UP, ft_strlen(key)) == 0
			|| ft_memcmp(key, KEY_LEFT, ft_strlen(key)) == 0)
	{
		if (!(curr = get_current_file(head)))
			return (-1);
		curr->file_current = FALSE;
		if (curr->prev)
			curr->prev->file_current = TRUE;
		else
		{
			while (curr->next)
				curr = curr->next;
			curr->file_current = TRUE;
		}
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_delete() removes a whole file node from the linked list.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_delete(t_files **head, char *key)
{
	t_files	*curr;

	if ((*(key + 0) == KEY_BACKSPACE && *(key + 1) == KEY_END)
			|| ft_memcmp(key, KEY_DELETE, ft_strlen(key)) == 0)
	{
		if (!(curr = get_current_file(head)))
			return (-1);
		if (curr->prev == NULL)
		{
			if (curr->next == NULL)
				clean_exit(head, g_mem);
			lst_del_head(head);
		}
		else if (curr->next == NULL)
			lst_del_tail(head, curr);
		else
			lst_del_middle(curr);
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_return() outputs file names to the terminal, separated by a space,
**	and exits.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_return(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_RETURN && *(key + 1) == KEY_END)
	{
		curr = *head;
		while (curr)
		{
			if (curr->file_selected == TRUE)
			{
				ft_putstr_fd(curr->file_name, STDOUT_FILENO);
				ft_putchar_fd(' ', STDOUT_FILENO);
			}
			curr = curr->next;
		}
		clean_exit(head, g_mem);
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_space() sets the current file to selected.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_space(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_SPACE && *(key + 1) == KEY_END)
	{
		if (!(curr = get_current_file(head)))
			return (-1);
		curr->file_selected = curr->file_selected == TRUE ? FALSE : TRUE;
		press_arrow_down(head, KEY_DOWN);
		return (1);
	}
	else
		return (0);
}
