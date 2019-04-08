/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdotdot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:13:03 by mate              #+#    #+#             */
/*   Updated: 2018/04/26 19:35:30 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	isdotdot(char *path)
{
	if (path && ft_strlen(path) >= 2 &&
			ft_strnequ(path, "..", 2) && (path[2] == '/' || !path[2]))
		return (1);
	return (0);
}
