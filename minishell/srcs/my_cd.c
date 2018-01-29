/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:31:52 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 21:39:09 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	get_env_val() looks into the environ to return the value of a specific var.
**	return value:
**	-	a string containing the value for the given name
**	-	NULL, if nothing has been found
*/

char		*get_env_val(t_env **env, char *name)
{
	t_env	*elm;

	elm = *env;
	while (elm)
	{
		if (ft_strcmp(elm->name, name) == 0)
			return (elm->value);
		elm = elm->next;
	}
	return (NULL);
}

/*
**	define_target() helps defining which directory cd will go into.
**	return value:
**	-	the right target we want
**	-	NULL if ???
*/

static char	*define_target(t_env **env, char **command)
{
	char	*target;
	char	*tmp;
	char	*cwd;

	if (ft_arrlen(command) == 1)
		return (ft_strdup(get_env_val(env, "HOME")));
	else if (ft_strncmp(*(command + 1), "-\0", 2) == 0)
	{
		ft_putendl(get_env_val(env, "OLDPWD"));
		return (ft_strdup(get_env_val(env, "OLDPWD")));
	}
	else if (**(command + 1) == '/')
		return (ft_strdup(*(command + 1)));
	else
	{
		if (!(cwd = getcwd(NULL, 1024)))
			exit(EXIT_FAILURE);
		if (!(tmp = ft_strjoin(cwd, "/")))
			exit(EXIT_FAILURE);
		ft_strdel(&cwd);
		if (!(target = ft_strjoin(tmp, *(command + 1))))
			exit(EXIT_FAILURE);
		ft_strdel(&tmp);
		return (target);
	}
}

/*
**	my_cd() is an implementation of the builtin `cd`.
*/

void		my_cd(t_env **env, char **command)
{
	char	*pwd;

	if (ft_arrlen(command) > 2)
		ft_putendl_fd("cd: too many arguments\nusage: cd [target...]", 2);
	else if (!(get_env_val(env, "PWD")) ||
			!(get_env_val(env, "HOME")) ||
			!(get_env_val(env, "OLDPWD")))
		ft_putendl_fd("cd: please set $HOME, $PWD & $OLDPWD", 2);
	else
	{
		if (!(pwd = define_target(env, command)))
			exit(EXIT_FAILURE);
		if (chdir(pwd) == 0)
		{
			env_replace(env, "OLDPWD", get_env_val(env, "PWD"));
			env_replace(env, "PWD", pwd);
		}
		else
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(*(command + 1), 2);
		}
		ft_strdel(&pwd);
	}
}
