/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:46:31 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 14:58:55 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	clean_exit() frees all allocated stuff, turns the terminal back as it was
**	before the program execution, and exit with EXIT_SUCCESS status.
**	-------------------------------------------------------------------------- +
*/

void		clean_exit(t_files **head, char *ds_mem)
{
	t_files	*curr;
	t_files	*tmp;

	ft_strdel(&ds_mem);
	curr = *head;
	while (curr)
	{
		ft_strdel(&curr->file_name);
		tmp = curr;
		curr = curr->next;
		ft_free(tmp);
	}
	ft_free(curr);
	def_term_mode();
	exit(EXIT_SUCCESS);
}

/*
**	-------------------------------------------------------------------------- +
**	clean_screen() wipes the screen.
**	-------------------------------------------------------------------------- +
*/

void		clean_screen(void)
{
	tputs(tgetstr("cl", NULL), 2, &tc_putc);
}

/*
**	-------------------------------------------------------------------------- +
**	print_usage() displays usage message for ft_select, as the following:
**	-------------------------------------------------------------------------- +
*/

static void	print_usage(char *prog_name)
{
	ft_putstr_fd(FG_RED, STDERR_FILENO);
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [ files... ]\n", STDERR_FILENO);
	ft_putstr_fd(FG_RESET, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/*
**	-------------------------------------------------------------------------- +
**	check_tty() checks if the given tty_name & file descriptor refer to
**	a valid terminal type device.
**	If not, it prints an accurate error message, and exit the program.
**	It returns EXIT_FAILURE if the tty is not valid, EXIT_SUCCESS else.
**	-------------------------------------------------------------------------- +
*/

static int	check_tty(char *tty_name)
{
	char	bp[1024];
	int		ret;

	if (!isatty(STDIN_FILENO))
	{
		ft_putendl_fd("Error: file decriptor does not refer to a \
valid terminal type device.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if ((ret = tgetent(bp, tty_name)) < 1)
	{
		if (ret == 0)
			ft_putendl_fd("Error: no such entry for tty name.", STDERR_FILENO);
		else if (ret == -1)
			ft_putendl_fd("Error: terminfo database could \
not be found.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
**	-------------------------------------------------------------------------- +
**	main() initializes signals, checks if number of parameters is correct,
**	checks if the current tty is valid, then call the main function that does
**	everything: exec_select().
**	It returns EXIT_FAILURE on failure, EXIT_SUCCESS on success.
**	-------------------------------------------------------------------------- +
*/

int			main(int argc, char **argv)
{
	char	*tty_name;

	signal_handler();
	if (argc < 2)
		print_usage(*(argv + 0));
	if (!(tty_name = getenv("TERM")))
	{
		ft_putendl_fd("Error: $TERM not in the environment.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (check_tty(tty_name) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (exec_select(argv) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
