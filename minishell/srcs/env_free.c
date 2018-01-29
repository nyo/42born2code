/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:34:18 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 18:37:44 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	env_free() frees up all the allocated memory in `t_env` linked list.
*/

void	env_free(t_env **env)
{
	t_env	*elm;
	t_env	*tmp;

	elm = *env;
	while (elm)
	{
		ft_strdel(&elm->name);
		ft_strdel(&elm->value);
		tmp = elm;
		elm = elm->next;
		ft_free(tmp);
	}
	ft_free(elm);
}
