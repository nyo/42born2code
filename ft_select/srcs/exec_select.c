/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:50:47 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 17:03:07 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	get_current_file() search for the file the user is currently on.
**	It returns the node containing the current file, or NULL if not found.
**	-------------------------------------------------------------------------- +
*/

t_files	*get_current_file(t_files **head)
{
	t_files	*current;

	current = *head;
	while (current)
	{
		if (current->file_current == TRUE)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*
**	-------------------------------------------------------------------------- +
**	exec_select() takes the selected files, stores them into a linked list,
**	then displays a graphical interface and applies the correct actions
**	corresponding to the key(s) pressed.
**	It exit with EXIT_FAILURE status on failure, or returns EXIT_SUCCESS else.
**	-------------------------------------------------------------------------- +
*/

int		exec_select(char **files)
{
	struct winsize	ws;
	t_files			*head;
	char			key[5];
	int				ret;

	head = NULL;
	if (!(g_mem = ft_strnew(0)))
		return (EXIT_FAILURE);
	if (lst_init(&head, files) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	raw_term_mode();
	clean_screen();
	while (1)
	{
		ioctl(STDERR_FILENO, TIOCGWINSZ, &ws);
		disp_back(ws, head);
		disp_list(ws, head);
		ret = read(STDERR_FILENO, key, 4);
		key[ret] = '\0';
		if (exec_key(&head, &g_mem, key) == EXIT_FAILURE)
			clean_exit(&head, g_mem);
		else
			clean_screen();
	}
	return (EXIT_SUCCESS);
}
