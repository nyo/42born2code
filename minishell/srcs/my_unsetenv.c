/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:40:24 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 18:32:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	is_name_ok() goes through the environ and checks if `name` exists.
**	return value:
**	0	-	name does not exist, nothing to remove
**	1	-	name exists, OK
*/

static int	is_name_ok(t_env **env, char *name)
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
**	env_remove() removes the element named `name` in the environ.
*/

static void	env_remove(t_env **env, char *name)
{
	t_env	*elm;
	t_env	*save;

	if (ft_strcmp((*env)->name, name) == 0)
	{
		ft_strdel(&(*env)->name);
		ft_strdel(&(*env)->value);
		save = (*env)->next;
		ft_free(*env);
		*env = save;
	}
	elm = *env;
	while (elm)
	{
		if (elm->next && ft_strcmp(elm->next->name, name) == 0)
		{
			ft_strdel(&elm->next->name);
			ft_strdel(&elm->next->value);
			save = elm->next->next;
			ft_free(elm->next);
			elm->next = save;
		}
		elm = elm->next;
	}
}

/*
**	my_unsetenv() is an implementation of the builtin `unsetenv`.
*/

void		my_unsetenv(t_env **env, char **command)
{
	if (ft_arrlen(command) != 2)
		ft_putendl_fd("usage: unsetenv [name]", 2);
	else if (is_name_ok(env, *(command + 1)) == 0)
	{
		ft_putstr_fd("unsetenv: incorrect element name: ", 2);
		ft_putendl_fd(*(command + 1), 2);
	}
	else
		env_remove(env, *(command + 1));
}
