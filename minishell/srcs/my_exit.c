/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:51:52 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 19:35:50 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	my_exit() is an implementation of the builtin `exit`.
*/

void	my_exit(t_env **env, char **command)
{
	int	status;

	status = 0;
	if (*(command + 1))
		status = ft_atoi(*(command + 1));
	ft_putstr(CL_RESET);
	env_free(env);
	ft_arrfree(command);
	exit(status);
}
