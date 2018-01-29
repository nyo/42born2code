/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 22:09:10 by anyo              #+#    #+#             */
/*   Updated: 2017/08/14 20:26:28 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	display_prompt() displays prompt message
*/

void	display_prompt(void)
{
	ft_putstr(CL_RESET);
	ft_putstr(CL_WHITE);
	ft_putstr("$> ");
	ft_putstr(CL_RESET);
}
