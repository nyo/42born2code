/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:30:27 by anyo              #+#    #+#             */
/*   Updated: 2017/08/24 15:28:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	cmd_len() returns the correct lenght to malloc `char **cmd`
*/

static int	cmd_len(char **command)
{
	int	len;
	int	i;

	len = 0;
	i = ft_strncmp(*(command + 1), "-i\0", 3) == 0 ? 2 : 1;
	while (*(command + i))
	{
		if (!(ft_strrchr(*(command + i), '=')))
			len++;
		i++;
	}
	return (len);
}

/*
**	valid_file() checks if `filename` is or is not a valid binary
**	return value:
**	0	-	`filename` is not a valid file/binary
**	1	-	`filename` is a vlid file/binary
*/

static int	valid_file(t_env **env, char *filename)
{
	char	*full_path;

	if (!(full_path = try_cmd_path(get_env_val(env, "PATH"), filename)))
		exit(EXIT_FAILURE);
	if (ft_strncmp(full_path, "nf\0", 3) == 0)
	{
		ft_strdel(&full_path);
		return (0);
	}
	else
	{
		ft_strdel(&full_path);
		return (1);
	}
}

/*
**	command_to_cmd() turns `char **command` into another array of char-pointers
**	containing only the executable part of the entered command.
**	return value:
**	-	NULL, if a part of `command` is not a binary or a new var
**	-	cmd w/ the binary name and parameters, if everything went well
**	-	cmd w/ only "nothing" string in it, if nothing has been added
*/

static char	**fill_cmd(char **command, int start)
{
	char	**cmd;
	int		len;
	int		i;

	i = 0;
	len = cmd_len(command);
	if (!(cmd = malloc(sizeof(char *) * (len + 1))))
		exit(EXIT_FAILURE);
	while (*(command + start))
	{
		if (!(*(cmd + i) = ft_strdup(*(command + start))))
			exit(EXIT_FAILURE);
		start++;
		i++;
	}
	*(cmd + i) = NULL;
	return (cmd);
}

static char	**command_to_cmd(t_env **env, char **command)
{
	char	**cmd;
	int		i;

	i = ft_strncmp(*(command + 1), "-i\0", 3) == 0 ? 2 : 1;
	while (*(command + i) && ft_strrchr(*(command + i), '='))
		i++;
	if (*(command + i) && valid_file(env, *(command + i)) == 1)
		return (fill_cmd(command, i));
	else if (*(command + i))
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(*(command + i), 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (NULL);
	}
	else
	{
		if (!(cmd = malloc(sizeof(char *) * (1 + 1))))
			exit(EXIT_FAILURE);
		if (!(*(cmd + 0) = ft_strdup("nothing")))
			exit(EXIT_FAILURE);
		*(cmd + 1) = NULL;
		return (cmd);
	}
}

/*
**	my_env() is an implementation of the builtin `env`.
*/

void		my_env(t_env **env, char **command)
{
	char	**environ;
	char	**cmd;
	char	*full_path;

	if (ft_arrlen(command) == 1)
	{
		env_print(*env);
		return ;
	}
	environ = env_to_environ(env, command);
	if (!(cmd = command_to_cmd(env, command)))
		;
	else if (ft_strncmp(*(cmd + 0), "nothing\0", 8) == 0)
		ft_putarr(environ);
	else
	{
		if (!(full_path = get_cmd_path(env, cmd)))
			exit(EXIT_FAILURE);
		exe_cute(environ, cmd, full_path);
		ft_strdel(&full_path);
	}
	ft_arrfree(environ);
	if (cmd)
		ft_arrfree(cmd);
}
