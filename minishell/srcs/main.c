/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:40:05 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 19:31:08 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	main() - where it all starts.
*/

int	main(int argc, char **argv, char **environ)
{
	char	**command;
	char	*line;
	t_env	*env;

	(void)argv;
	if (argc == 1)
	{
		env_init(&env, environ);
		while (1)
		{
			signal(SIGINT, sig_init);
			display_prompt();
			ft_putstr(ft_atoi(get_env_val(&env, "COLOR")) == 1 ? CL_BLUE : "");
			get_next_line(0, &line);
			if (is_line_blank(line) == 0)
			{
				if (!(command = cmd_format(&env, line)))
					exit(EXIT_FAILURE);
				cmd_execute(&env, command);
				ft_arrfree(command);
			}
			ft_strdel(&line);
		}
	}
	exit(EXIT_SUCCESS);
}
