/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:22:11 by anyo              #+#    #+#             */
/*   Updated: 2017/08/14 20:00:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	put_env_var() goes through the env list, and prints the value
**	corresponding to hte matching name for `command`.
**	return value:
**	0	-	no match found
**	1	-	match found, value printed
*/

static int	put_env_var(char *command, t_env **env)
{
	t_env	*elm;

	command++;
	elm = *env;
	while (elm)
	{
		if (ft_strcmp(elm->name, command) == 0)
		{
			ft_putstr(elm->value);
			return (1);
		}
		elm = elm->next;
	}
	return (0);
}

/*
**	my_echo() (and subfunctions...) is an implementation of the builtin `cd`.
*/

static void	my_echo_n(char **command, t_env **env)
{
	int	i;
	int	has_been_printed;

	i = 2;
	while (*(command + i))
	{
		has_been_printed = 1;
		if (ft_strncmp(*(command + i), "$", 1) == 0)
			has_been_printed = put_env_var(*(command + i), env);
		else
			ft_putstr(*(command + i));
		if (has_been_printed == 1 && *(command + i + 1))
			ft_putchar(' ');
		i++;
	}
}

static void	my_echo_0(char **command, t_env **env)
{
	int	i;
	int	has_been_printed;

	i = 1;
	while (*(command + i))
	{
		has_been_printed = 1;
		if (ft_strncmp(*(command + i), "$", 1) == 0)
			has_been_printed = put_env_var(*(command + i), env);
		else
			ft_putstr(*(command + i));
		if (*(command + i + 1))
			ft_putchar(has_been_printed == 1 ? ' ' : 0);
		else
			ft_putchar('\n');
		i++;
	}
}

void		my_echo(t_env **env, char **command)
{
	if (ft_arrlen(command) == 1)
		ft_putchar('\n');
	else if (ft_strncmp(*(command + 1), "-n\0", 3) == 0)
		my_echo_n(command, env);
	else
		my_echo_0(command, env);
}
