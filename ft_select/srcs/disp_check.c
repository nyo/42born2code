/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 21:48:08 by anyo              #+#    #+#             */
/*   Updated: 2017/09/27 14:40:01 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	get_lst_width() returns the lenght of the longest file name, rounded up to
**	the first multiple of 4 (to get a clean padding), of the lined list.
**	-------------------------------------------------------------------------- +
*/

int			get_lst_width(t_files *head)
{
	size_t	width;

	width = 0;
	while (head)
	{
		if (ft_strlen(head->file_name) > width)
			width = ft_strlen(head->file_name);
		head = head->next;
	}
	while ((width % 4) != 0)
		width++;
	return ((int)width);
}

/*
**	-------------------------------------------------------------------------- +
**	get_lst_height() returns the height (lenght) of the linked list.
**	-------------------------------------------------------------------------- +
*/

int			get_lst_height(t_files *head)
{
	int height;

	height = 0;
	while (head)
	{
		height++;
		head = head->next;
	}
	return (height);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_check_help() checks if the help message at the bottom of the screen
**	can be displayed or not.
**	If so, it returns EXIT_SUCCESS, else, it returns EXIT_FAILURE.
**	-------------------------------------------------------------------------- +
*/

int			disp_check_help(struct winsize ws, char *help_content)
{
	if ((ft_strlen(help_content) + 2 + 2) > ws.ws_col)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_no_split() handles the part of disp_check() that does not split list.
**	It returns -1 if the screen is too small anyway, 0 if the screen is large
**	enough to display the complete list, or 1 if it needs to be splitted.
**	-------------------------------------------------------------------------- +
*/

static int	disp_no_split(struct winsize ws, int height, int width)
{
	if (width > ws.ws_col)
		return (-1);
	else if (height <= ws.ws_row && width <= ws.ws_col)
		return (0);
	else
		return (1);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_check() checks if the linked list fits in the current window size.
**	If it does on the first check, it returns 0;
**	Else, it tries to split the list to check if it can fits in the current
**	window with another display. If it finds a way to display it, it returns how
**	many time we need to split the list, -1 else.
**	-------------------------------------------------------------------------- +
*/

int			disp_check(struct winsize ws, int lst_h, int lst_w)
{
	int	nb_split;
	int spaces;
	int	height;
	int	width;

	spaces = 0;
	nb_split = 2;
	width = lst_w + 2 + 2 + 2 + 2;
	height = lst_h + 3 + 3 + 1 + 1;
	if (disp_no_split(ws, height, width) != 1)
		return (disp_no_split(ws, height, width));
	if ((height % 2) != 0)
		height++;
	while (1)
	{
		spaces = (nb_split - 1) * 2;
		height = (lst_h / nb_split) + 3 + 3 + 1 + 1;
		width = (lst_w * nb_split) + spaces + 2 + 2 + 2 + 2;
		if (height <= ws.ws_row && width <= ws.ws_col)
			return (nb_split);
		else if (width > ws.ws_col)
			return (-1);
		nb_split += 2;
	}
}
