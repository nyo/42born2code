/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:42:10 by anyo              #+#    #+#             */
/*   Updated: 2017/08/26 14:30:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	exe_cute() takes an array of strings containing the command details,
**	another one containing the environ, and a string of the full path to
**	the binary.
**	If it is possible, it executes it.
*/

void		exe_cute(char **environ, char **command, char *full_path)
{
	int		status;
	pid_t	pid;

	pid = fork();
	signal(SIGINT, sig_exe);
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		if ((status = execve(full_path, command, environ)) == -1)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putendl_fd(*(command + 0), 2);
			exit(status);
		}
		if (kill(pid, SIGINT) == -1)
			exit(status);
		exit(status);
	}
	else if (waitpid(pid, &status, 0) == -1)
		exit(EXIT_FAILURE);
}

/*
**	get_full_path() checks if the command is already a full path, and
**	if $PATH is set.
*/

static char	*get_full_path(t_env **env, char **command)
{
	if (**(command + 0) == '/')
		return (ft_strdup(*(command + 0)));
	if ((get_env_val(env, "PATH")))
		return (get_cmd_path(env, command));
	else
		return (NULL);
}

/*
**	cmd_isnt_mine() converts the environ, gets the command's full path,
**	and call exe_cute() with thoses.
*/

static void	cmd_isnt_mine(t_env **env, char **command)
{
	char	**environ;
	char	*full_path;

	environ = env_to_arr(env);
	full_path = get_full_path(env, command);
	exe_cute(environ, command, full_path);
	if (full_path)
		ft_strdel(&full_path);
	ft_arrfree(environ);
}

/*
**	cmd_execute() (tries to) execute the entered command.
*/

void		cmd_execute(t_env **env, char **command)
{
	ft_putstr(ft_atoi(get_env_val(env, "COLOR")) == 1 ? CL_YELLOW : "");
	if (ft_strncmp(*(command + 0), "echo\0", 5) == 0)
		my_echo(env, command);
	else if (ft_strncmp(*(command + 0), "exit\0", 5) == 0)
		my_exit(env, command);
	else if (ft_strncmp(*(command + 0), "env\0", 4) == 0)
		my_env(env, command);
	else if (ft_strncmp(*(command + 0), "setenv\0", 7) == 0)
		my_setenv(env, command);
	else if (ft_strncmp(*(command + 0), "unsetenv\0", 8) == 0)
		my_unsetenv(env, command);
	else if (ft_strncmp(*(command + 0), "cd\0", 3) == 0)
		my_cd(env, command);
	else if (ft_strncmp(*(command + 0), "togglecolor\0", 12) == 0)
		my_togglecolor(env);
	else
		cmd_isnt_mine(env, command);
}
