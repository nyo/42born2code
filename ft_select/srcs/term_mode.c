/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:13:19 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 15:02:52 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	raw_term_mode() turns the raw mode of the terminal on. To do so, it
**	disables the canonical input mode, echo mode & disables output processing.
**	It returns EXIT_FAILURE on failure, EXIT_SUCCESS on success.
**
**	For more informations about canonical mode, see:
**	http://man7.org/linux/man-pages/man3/termios.3.html
**
**	@attr.c_lflag &= ~ICANON			>>>	disables canonical input
**	@attr.c_lflag &= ~ECHO				>>>	disables echo
**	@attr.c_oflag &= ~OPOST				>>>	disables performing output
**											processing
**
**	The settings of VMIN and VTIME determine the circumstances in which a
**	read(2) completes, in our case :
**		-	read(2) blocks until MIN bytes are available, and returns up to
**			the number of bytes requested.
**
**	@tcsetattr(..., TCSADRAIN, ...)		>>>	the change occurs after all output
**											written to fd has been transmitted
**
**	@tputs(tgetstr("vi", NULL), ...)	>>>	makes cursor invisible
**	@tputs(tgetstr("ti", NULL), ...)	>>>	starts using cursor motion
**	-------------------------------------------------------------------------- +
*/

void	raw_term_mode(void)
{
	struct termios	attr;

	if (tcgetattr(STDERR_FILENO, &attr) == -1)
	{
		ft_putendl_fd("Error: could not get termios.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	attr.c_lflag &= ~ICANON;
	attr.c_lflag &= ~ECHO;
	attr.c_oflag &= ~OPOST;
	attr.c_cc[VTIME] = 0;
	attr.c_cc[VMIN] = 1;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, &attr) == -1)
	{
		ft_putendl_fd("Error: could not set terminal.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tputs(tgetstr("vi", NULL), 0, &tc_putc);
	tputs(tgetstr("ti", NULL), 0, &tc_putc);
}

/*
**	-------------------------------------------------------------------------- +
**	def_term_mode() basically sets the terminal settings back as it was before
**	the call to raw_term_mode() function.
**	It returns EXIT_FAILURE on failure, EXIT_SUCCESS on success.
**	-------------------------------------------------------------------------- +
*/

void	def_term_mode(void)
{
	struct termios	attr;

	if (tcgetattr(STDERR_FILENO, &attr) == -1)
	{
		ft_putendl_fd("Error: could not get termios.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	attr.c_lflag |= ICANON;
	attr.c_lflag |= ECHO;
	attr.c_oflag |= OPOST;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, &attr) == -1)
	{
		ft_putendl_fd("Error: could not set terminal.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tputs(tgetstr("ve", NULL), 0, &tc_putc);
	tputs(tgetstr("te", NULL), 0, &tc_putc);
}
