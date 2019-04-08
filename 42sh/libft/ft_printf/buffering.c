/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:09:38 by mate              #+#    #+#             */
/*   Updated: 2017/12/13 18:29:44 by mate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	print_buffer(t_env *env)
{
	env->ret += env->j;
	if ((write(env->fd, env->buf, env->j) == -1))
		exit(EXIT_FAILURE);
	env->j = 0;
}

void	putchar_to_buffer(char c, t_env *env)
{
	env->buf[env->j++] = c;
	if (env->j == BUFF_SIZE)
		print_buffer(env);
}

void	putstr_to_buffer(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		env->buf[env->j++] = str[i++];
		if (env->j == BUFF_SIZE)
			print_buffer(env);
	}
}
