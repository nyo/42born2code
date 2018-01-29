/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:24:11 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 14:45:31 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	sig_int() is executed when an INT ("interrupt") signal has been received
**	(when the user presses Ctrl + C). This causes the process to terminate.
**	-------------------------------------------------------------------------- +
*/

void	sig_int(int sig)
{
	if (sig == SIGINT)
		clean_exit(&g_files, g_mem);
}

/*
**	-------------------------------------------------------------------------- +
**	sig_tstp() is executed when a TSTP ("terminal stop") signal has been
**	received (when the user presses Ctrl + Z). This suspends the current process
**	execution, by faking the input with ioctl() and inserting the SUSP (suspend)
**	byte (character) in the input queue. It causes a SIGTSTP signal to be sent
**	to all processes in the foreground job associated with the terminal.
**	-------------------------------------------------------------------------- +
*/

void	sig_tstp(int sig)
{
	char			byte[2];
	struct termios	attr;

	if (sig == SIGTSTP)
	{
		if (tcgetattr(STDERR_FILENO, &attr) == -1)
		{
			ft_putendl_fd("Error: could not get termios.", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		byte[0] = attr.c_cc[VSUSP];
		byte[1] = KEY_END;
		def_term_mode();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, byte);
	}
}

/*
**	-------------------------------------------------------------------------- +
**	sig_cont() is executed when the user instructs the operating system to
**	continue (restart) a process previously paused by the [...] SIGTSTP signal.
**	It turns the terminal back in raw mode, fakes an input key to update the
**	display (using sig_winch()) then call signal_handler() to initialize
**	signals again.
**	-------------------------------------------------------------------------- +
*/

void	sig_cont(int sig)
{
	if (sig == SIGCONT)
	{
		raw_term_mode();
		sig_winch(SIGWINCH);
		signal_handler();
	}
}

/*
**	-------------------------------------------------------------------------- +
**	sig_winch() is executed when a window size change is detected (w/ SIGWINCH).
**	If so, we use ioctl() with `TIOCSTI` to fake input, by inserting a given
**	byte in the input queue. The character in byte is a random non-ASCII value,
**	it permits real-time-refresh of the display on a window resizing.
**	-------------------------------------------------------------------------- +
*/

void	sig_winch(int sig)
{
	char	byte[2];

	if (sig == SIGWINCH)
	{
		byte[0] = KEY_RESIZE;
		byte[1] = KEY_END;
		ioctl(STDERR_FILENO, TIOCSTI, byte);
	}
}

/*
**	-------------------------------------------------------------------------- +
**	signal_handler() initializes all signal handling functions.
**	-------------------------------------------------------------------------- +
*/

void	signal_handler(void)
{
	signal(SIGINT, sig_int);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGWINCH, sig_winch);
}
