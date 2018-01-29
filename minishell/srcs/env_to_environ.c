/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:25:11 by anyo              #+#    #+#             */
/*   Updated: 2017/08/11 13:36:44 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	should_i_add() checks if a node from env has to be replaced.
**	return value:
**	0	-	name has been found in `char **command`, dont add name to the array
**	1	-	name has not been found in `char **command`, opposite
*/

static int	should_i_add(char **command, char *name)
{
	int	i;

	i = 0;
	while (*(command + i))
	{
		if ((ft_strncmp(*(command + i), name, ft_strlen(name))) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**	env_len() returns the correct lenght to malloc `char **environ`
*/

static int	env_len(t_env **env, char **command)
{
	t_env	*elm;
	int		len;
	int		i;

	i = 0;
	len = 0;
	elm = *env;
	if (ft_strncmp(*(command + 1), "-i\0", 3) != 0)
	{
		while (elm)
		{
			if (should_i_add(command, elm->name) == 1)
				len++;
			elm = elm->next;
		}
	}
	while (*(command + i))
	{
		if (ft_strrchr(*(command + i), '='))
			len++;
		i++;
	}
	return (len);
}

/*
**	add_new_var() adds the new var we want in the fresh new `char **environ`
**	return value:
**	-	where we stopped adding values to `char **environ`
*/

static int	add_new_var(char **environ, char **command)
{
	int	len;
	int	i;

	i = 0;
	len = ft_arrlen(command) - 1;
	while (len >= 0 && *(command + len))
	{
		if (ft_strrchr(*(command + len), '='))
		{
			if (!(*(environ + i) = ft_strdup(*(command + len))))
				exit(EXIT_FAILURE);
			i++;
		}
		len--;
	}
	return (i);
}

/*
**	add_old_var() adds the old var we want (from `t_env **env`)
**	return value:
**	-	where we stopped adding values to `char **environ`
*/

static int	add_old_var(t_env **env, char **environ, char **command, int i)
{
	t_env	*elm;
	char	*tmp;

	elm = *env;
	while (elm)
	{
		if (should_i_add(command, elm->name) == 1)
		{
			if (!(tmp = ft_strjoin(elm->name, "=")))
				exit(EXIT_FAILURE);
			if (!(*(environ + i) = ft_strjoin(tmp, elm->value)))
				exit(EXIT_FAILURE);
			ft_strdel(&tmp);
			i++;
		}
		elm = elm->next;
	}
	return (i);
}

/*
**	env_to_environ() returns an array of char-pointers, which are
**	environ + new values added/replaced.
*/

char		**env_to_environ(t_env **env, char **command)
{
	char	**environ;
	int		len;
	int		i;

	len = env_len(env, command);
	if (!(environ = malloc(sizeof(char *) * (len + 1))))
		exit(EXIT_FAILURE);
	i = add_new_var(environ, command);
	if (ft_strncmp(*(command + 1), "-i\0", 3) != 0)
		i = add_old_var(env, environ, command, i);
	*(environ + i) = NULL;
	ft_arrrev(environ);
	return (environ);
}
