/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_togglecolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:00:20 by anyo              #+#    #+#             */
/*   Updated: 2017/08/26 14:20:49 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	my_togglecolor() enables or disables the shell's color mode.
*/

void	my_togglecolor(t_env **env)
{
	int	status;

	status = ft_atoi(get_env_val(env, "COLOR"));
	if (status == 0)
		env_replace(env, "COLOR", "1");
	else
		env_replace(env, "COLOR", "0");
}
