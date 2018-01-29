/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 21:18:08 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 16:32:45 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	------------------------------------------------------------------------- +
**	disp_title() displays a title at the top of the screen.
**	------------------------------------------------------------------------- +
*/

static int	disp_title(struct winsize ws)
{
	char	*title_content;
	int		x;
	int		y;

	if (!(title_content = ft_strdup("-+- ft_select -+-")))
		return (EXIT_FAILURE);
	x = (ws.ws_col / 2) - (ft_strlen(title_content) / 2);
	y = 1;
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, &tc_putc);
	ft_putstr_fd(FG_BLACK, STDERR_FILENO);
	ft_putstr_fd(BG_WHITE, STDERR_FILENO);
	ft_putstr_fd(title_content, STDERR_FILENO);
	ft_putstr_fd(BG_RESET, STDERR_FILENO);
	ft_putstr_fd(FG_RESET, STDERR_FILENO);
	ft_strdel(&title_content);
	return (EXIT_SUCCESS);
}

/*
**	------------------------------------------------------------------------- +
**	disp_help() displays informations at the bottom of the screen.
**	------------------------------------------------------------------------- +
*/

static int	disp_help(struct winsize ws)
{
	char	*help_content;
	int		x;
	int		y;

	if (!(help_content = ft_strdup(
	"[arrows] move [space] select [*] all [-] none \
[~] color [$] check [del] remove [esc] quit")))
		return (EXIT_FAILURE);
	if (disp_check_help(ws, help_content) == EXIT_FAILURE)
	{
		ft_strdel(&help_content);
		return (EXIT_SUCCESS);
	}
	x = ws.ws_row - 2;
	y = (ws.ws_col / 2) - (ft_strlen(help_content) / 2);
	tputs(tgoto(tgetstr("cm", NULL), y, x), 1, &tc_putc);
	ft_putstr_fd(FG_BLACK, STDERR_FILENO);
	ft_putstr_fd(BG_WHITE, STDERR_FILENO);
	ft_putstr_fd(C_ITALIC_ON, STDERR_FILENO);
	ft_putstr_fd(help_content, STDERR_FILENO);
	ft_putstr_fd(C_ITALIC_OFF, STDERR_FILENO);
	ft_putstr_fd(BG_RESET, STDERR_FILENO);
	ft_putstr_fd(FG_RESET, STDERR_FILENO);
	ft_strdel(&help_content);
	return (EXIT_SUCCESS);
}

/*
**	------------------------------------------------------------------------- +
**	disp_cols() displays columns on each side of the screen.
**	------------------------------------------------------------------------- +
*/

static void	disp_cols(struct winsize ws, int i)
{
	tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, &tc_putc);
	ft_putstr_fd(BG_WHITE, STDERR_FILENO);
	ft_putstr_fd("  ", STDERR_FILENO);
	ft_putstr_fd(BG_RESET, STDERR_FILENO);
	tputs(tgoto(tgetstr("cm", NULL), ws.ws_col - 2, i), 1, &tc_putc);
	ft_putstr_fd(BG_WHITE, STDERR_FILENO);
	ft_putstr_fd("  ", STDERR_FILENO);
	ft_putstr_fd(BG_RESET, STDERR_FILENO);
}

/*
**	------------------------------------------------------------------------- +
**	disp_rows() displays a bar at the top (header) & bottom of the screen.
**	------------------------------------------------------------------------- +
*/

static void	disp_rows(struct winsize ws, int i)
{
	int	j;

	j = 0;
	while (j < ws.ws_col)
	{
		tputs(tgoto(tgetstr("cm", NULL), j, i), 1, &tc_putc);
		ft_putstr_fd(BG_WHITE, STDERR_FILENO);
		ft_putchar_fd(' ', STDERR_FILENO);
		ft_putstr_fd(BG_RESET, STDERR_FILENO);
		j++;
	}
}

/*
**	------------------------------------------------------------------------- +
**	disp_back() displays a background for ft_select.
**	------------------------------------------------------------------------- +
*/

void		disp_back(struct winsize ws, t_files *head)
{
	int	i;

	i = 0;
	while (i < ws.ws_row)
	{
		if (i == 0 || i == 1 || i == 2 ||
				i == ws.ws_row - 1 || i == ws.ws_row - 2 || i == ws.ws_row - 3)
			disp_rows(ws, i);
		disp_cols(ws, i);
		i++;
	}
	if (disp_title(ws) == EXIT_FAILURE)
		clean_exit(&head, g_mem);
	if (disp_help(ws) == EXIT_FAILURE)
		clean_exit(&head, g_mem);
}
