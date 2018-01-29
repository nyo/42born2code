/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:03:11 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 19:29:41 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	is_name_ok() checks if name contains only alnum characters and/or `_`.
**	return value:
**	0	-	name is NOT OK
**	1	-	name is OK
*/

static int	is_name_ok(char *name)
{
	int	i;

	i = 0;
	while (*(name + i))
	{
		if (ft_isalnum(*(name + i)) != 1 && *(name + i) != '_')
			return (0);
		i++;
	}
	return (1);
}

/*
**	already_existst() goes through the environ and checks if the name we want
**	to add already exists, or not.
**	return value:
**	0	-	does not exist already
**	1	-	it already exists
*/

static int	already_exists(t_env **env, char *name)
{
	t_env	*elm;

	elm = *env;
	while (elm)
	{
		if (ft_strcmp(elm->name, name) == 0)
			return (1);
		elm = elm->next;
	}
	return (0);
}

/*
**	env_append() appends the name/value couple to the linked list (= environ)
*/

void		env_append(t_env **env, char *name, char *value)
{
	t_env	*elm;

	if (already_exists(env, name) == 1)
	{
		env_replace(env, name, value);
		return ;
	}
	elm = *env;
	while (elm)
		elm = elm->next;
	if (!(elm = malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	if (!(elm->name = ft_strdup(name)))
		exit(EXIT_FAILURE);
	if (!(elm->value = ft_strdup(value)))
		exit(EXIT_FAILURE);
	elm->next = *env;
	*env = elm;
}

/*
**	env_replace() replaces the value of `name` with a new `value`
**	in the linked list.
*/

void		env_replace(t_env **env, char *name, char *value)
{
	t_env	*elm;

	elm = *env;
	while (elm)
	{
		if (ft_strcmp(elm->name, name) == 0)
		{
			ft_strdel(&elm->value);
			if (!(elm->value = ft_strdup(value)))
				exit(EXIT_FAILURE);
		}
		elm = elm->next;
	}
}

/*
**	my_setenv() is an implementation of the builtin `setenv`.
*/

void		my_setenv(t_env **env, char **command)
{
	if (ft_arrlen(command) != 3)
		ft_putendl_fd("usage: setenv [name] [value]", 2);
	else if (is_name_ok(*(command + 1)) == 0)
	{
		ft_putstr_fd("setenv: not valid in this context: ", 2);
		ft_putendl_fd(*(command + 1), 2);
	}
	else if (already_exists(env, *(command + 1)) == 1)
		env_replace(env, *(command + 1), *(command + 2));
	else
		env_append(env, *(command + 1), *(command + 2));
}
