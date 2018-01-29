/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:15:31 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 18:58:33 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	sig_exe() handles interruption signals on a running process
*/

void	sig_exe(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, sig_exe);
	}
}

/*
**	sig_init() handles interruption signals on the program
*/

void	sig_init(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		display_prompt();
		signal(SIGINT, sig_init);
	}
}
