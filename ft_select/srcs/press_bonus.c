/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:07:55 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 15:21:33 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	press_ds() searches dynamically in the file list.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_ds(t_files **head, char **ds_mem, char *key)
{
	t_files	*move;
	t_files	*curr;

	move = *head;
	if (!(curr = get_current_file(head)))
		return (-1);
	while (move)
	{
		if (ft_strncmp(move->file_name, *ds_mem, ft_strlen(*ds_mem)) == 0)
		{
			curr->file_current = FALSE;
			move->file_current = TRUE;
			return (1);
		}
		move = move->next;
	}
	ft_strdel(ds_mem);
	if (!(*ds_mem = ft_strdup(key)))
		return (-1);
	return (1);
}

/*
**	-------------------------------------------------------------------------- +
**	press_unselect_all() sets all file to un-selected at once.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_unselect_all(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_S_NONE && *(key + 1) == KEY_END)
	{
		curr = *head;
		while (curr)
		{
			curr->file_selected = FALSE;
			curr = curr->next;
		}
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_select_all() sets all files to selected at once.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_select_all(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_S_ALL && *(key + 1) == KEY_END)
	{
		curr = *head;
		while (curr)
		{
			curr->file_selected = TRUE;
			curr = curr->next;
		}
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_check() applies italic font to files that does not exist.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_check(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_HIDE && *(key + 1) == KEY_END)
	{
		curr = *head;
		while (curr)
		{
			if (access(curr->file_name, F_OK) == -1)
			{
				if (curr->file_exists == TRUE)
					curr->file_exists = FALSE;
				else if (curr->file_exists == FALSE)
					curr->file_exists = TRUE;
			}
			curr = curr->next;
		}
		return (1);
	}
	else
		return (0);
}

/*
**	-------------------------------------------------------------------------- +
**	press_color() sets colorizing of file names to on, or off.
**	It returns -1 on error, 0 if the function is not associated to the given
**	key byte, or 1 if everything has been successfully done.
**	-------------------------------------------------------------------------- +
*/

int	press_color(t_files **head, char *key)
{
	t_files	*curr;

	if (*(key + 0) == KEY_COLOR && *(key + 1) == KEY_END)
	{
		curr = *head;
		while (curr)
		{
			if (curr->file_color == TRUE)
				curr->file_color = FALSE;
			else if (curr->file_color == FALSE)
				curr->file_color = TRUE;
			curr = curr->next;
		}
		return (1);
	}
	else
		return (0);
}
