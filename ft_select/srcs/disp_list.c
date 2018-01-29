/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:29:56 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 16:27:51 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	disp_color_file_name() adds color (or not) to the printed file names,
**	according to their extension.
**	If flag is RESET, it resets the color, else it adds some.
**	-------------------------------------------------------------------------- +
*/

static void	disp_color_file_name(char *file_name, int flag)
{
	int	ext;

	ext = ft_strlen(file_name) - 1;
	while (ext > -1 && *(file_name + ext) != '.')
		ext--;
	if (flag == RESET)
		ft_putstr_fd(FG_RESET, STDERR_FILENO);
	else if (ft_strcmp(file_name + ft_strlen(file_name) - 8, "Makefile") == 0)
		ft_putstr_fd(FG_RED, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".c") == 0)
		ft_putstr_fd(FG_GREEN, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".h") == 0)
		ft_putstr_fd(FG_BLUE, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".py") == 0)
		ft_putstr_fd(FG_MAGENTA, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".sh") == 0)
		ft_putstr_fd(FG_CYAN, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".txt") == 0)
		ft_putstr_fd(FG_YELLOW, STDERR_FILENO);
	else if (ft_strcmp(file_name + ext, ".log") == 0)
		ft_putstr_fd(FG_BLACK, STDERR_FILENO);
	else
		ft_putstr_fd(FG_WHITE, STDERR_FILENO);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_print_file_name() prints file names, with corresponding syntax.
**	-------------------------------------------------------------------------- +
*/

static void	disp_print_file_name(t_files *file_data)
{
	int	is_dir;

	is_dir = open(file_data->file_name, O_DIRECTORY) == -1 ? FALSE : TRUE;
	if (is_dir == TRUE)
		ft_putstr_fd(C_BOLD_ON, STDERR_FILENO);
	if (file_data->file_selected == TRUE)
		ft_putstr_fd(C_INVERSE_ON, STDERR_FILENO);
	if (file_data->file_current == TRUE)
		ft_putstr_fd(C_UNDERLINE_ON, STDERR_FILENO);
	if (file_data->file_exists == FALSE)
		ft_putstr_fd(C_ITALIC_ON, STDERR_FILENO);
	if (file_data->file_color == TRUE)
		disp_color_file_name(file_data->file_name, TRUE);
	ft_putstr_fd(file_data->file_name, STDERR_FILENO);
	if (file_data->file_color == TRUE)
		disp_color_file_name(file_data->file_name, RESET);
	if (file_data->file_exists == FALSE)
		ft_putstr_fd(C_ITALIC_OFF, STDERR_FILENO);
	if (file_data->file_current == TRUE)
		ft_putstr_fd(C_UNDERLINE_OFF, STDERR_FILENO);
	if (file_data->file_selected == TRUE)
		ft_putstr_fd(C_INVERSE_OFF, STDERR_FILENO);
	if (is_dir == TRUE)
		ft_putstr_fd(C_BOLD_OFF, STDERR_FILENO);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_error() displays error screen as long as the screen is too small.
**	-------------------------------------------------------------------------- +
*/

static int	disp_error(struct winsize ws)
{
	char	*error_content;
	int		x;
	int		y;

	y = -1;
	clean_screen();
	ft_putstr_fd(BG_BLUE, STDERR_FILENO);
	while (++y < ws.ws_row)
	{
		x = -1;
		while (++x < ws.ws_col)
		{
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, &tc_putc);
			ft_putchar_fd(' ', STDERR_FILENO);
		}
	}
	if (!(error_content = ft_strdup("screen size is too small")))
		return (EXIT_FAILURE);
	x = (ws.ws_col / 2) - (ft_strlen(error_content) / 2);
	y = ws.ws_row / 2;
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, &tc_putc);
	ft_putstr_fd(error_content, STDERR_FILENO);
	ft_putstr_fd(BG_RESET, STDERR_FILENO);
	ft_strdel(&error_content);
	return (EXIT_SUCCESS);
}

/*
**	-------------------------------------------------------------------------- +
**	disp_while() goes through the linked list and prints each file name @ the
**	correct coordinates (according to the window size).
**	-------------------------------------------------------------------------- +
*/

static void	disp_while(t_files *head, int nb_split, int lst_h, int lst_w)
{
	int	x;
	int	y;

	x = 4;
	y = 4;
	while (head)
	{
		if (nb_split != 0 && ((y - 4) == (lst_h / nb_split)))
		{
			x += lst_w + 2;
			y = 4;
		}
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, &tc_putc);
		disp_print_file_name(head);
		head = head->next;
		y++;
	}
}

/*
**	-------------------------------------------------------------------------- +
**	disp_list() displays a list of the files passed to the program, or an error
**	screen if window size is too small to display all the file names.
**	-------------------------------------------------------------------------- +
*/

void		disp_list(struct winsize ws, t_files *head)
{
	int	lst_height;
	int	lst_width;
	int	nb_split;

	lst_width = get_lst_width(head);
	lst_height = get_lst_height(head);
	nb_split = disp_check(ws, lst_height, lst_width);
	while (nb_split != 0 && (lst_height % nb_split) != 0)
		lst_height++;
	if (nb_split == -1)
	{
		if (disp_error(ws) == EXIT_FAILURE)
			clean_exit(&head, g_mem);
	}
	else
		disp_while(head, nb_split, lst_height, lst_width);
}
