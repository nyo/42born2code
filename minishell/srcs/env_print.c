/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:44:39 by anyo              #+#    #+#             */
/*   Updated: 2017/08/14 20:20:38 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	env_print() prints names & values the same way `env` command does.
*/

void	env_print(t_env *env)
{
	if (!env)
		return ;
	env_print(env->next);
	ft_putstr(env->name);
	ft_putstr("=");
	ft_putendl(env->value);
}
