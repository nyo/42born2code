/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 20:03:39 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 22:25:11 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	env_len() returns the lenght of the `t_env **` linked list.
*/

static int	env_len(t_env **env)
{
	t_env	*elm;
	int		len;

	len = 0;
	elm = *env;
	while (elm)
	{
		len++;
		elm = elm->next;
	}
	return (len);
}

/*
**	env_to_arr() returns the environ linked list back into an array of
**	char-pointers .
*/

char		**env_to_arr(t_env **env)
{
	char	**arr;
	char	*tmp;
	t_env	*elm;
	int		len;
	int		i;

	i = 0;
	tmp = NULL;
	elm = *env;
	len = env_len(env);
	if (!(arr = malloc(sizeof(char *) * (len + 1))))
		exit(EXIT_FAILURE);
	while (elm)
	{
		if (!(tmp = ft_strjoin(elm->name, "=")))
			exit(EXIT_FAILURE);
		if (!(*(arr + i) = ft_strjoin(tmp, elm->value)))
			exit(EXIT_FAILURE);
		ft_strdel(&tmp);
		elm = elm->next;
		i++;
	}
	*(arr + i) = NULL;
	ft_arrrev(arr);
	return (arr);
}
