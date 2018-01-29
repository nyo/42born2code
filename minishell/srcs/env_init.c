/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 18:44:50 by anyo              #+#    #+#             */
/*   Updated: 2017/08/23 20:06:52 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	env_shlvl_up() increase $SHLVL by one if `char *name` is "SHLVLUP".
*/

static int	env_shlvl_up(char *name)
{
	if (ft_strncmp(name, "SHLVL\0", 6) == 0)
		return (1);
	return (0);
}

/*
**	env_init() (and subfunctions...) turns the array of environ strings,
**	into a linked list of environ values.
*/

static char	*strdup_v(char *str)
{
	char	*ptr;
	int		len;

	len = 0;
	if (!str)
		return (NULL);
	while (*(str + len) != '=')
		len++;
	if (!(ptr = ft_strnew(ft_strlen(str) - len - 1)))
		return (NULL);
	return (ft_strrcpy(ptr, str, len + 1));
}

static char	*strdup_n(char *str)
{
	char	*ptr;
	int		len;

	len = 0;
	if (!str)
		return (NULL);
	while (*(str + len) != '=')
		len++;
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(ptr, str, len));
}

static char	*strdup_u(char *str)
{
	char	*tmp1;
	char	*tmp2;

	if (!(tmp1 = strdup_v(str)))
		return (NULL);
	if (!(tmp2 = ft_itoa(ft_atoi(tmp1) + 1)))
		return (NULL);
	ft_strdel(&tmp1);
	return (tmp2);
}

/*
**	env_init fact: by default, if the original environ does not
**	contain a $PATH entry, set it to "/bin:/usr/bin" as csh(1) does.
*/

void		env_init(t_env **env, char **environ)
{
	t_env	*elm;
	int		i;

	i = 0;
	while (*(environ + i))
	{
		if (!(elm = malloc(sizeof(t_env))))
			exit(EXIT_FAILURE);
		if (!(elm->name = strdup_n(*(environ + i))))
			exit(EXIT_FAILURE);
		if (env_shlvl_up(elm->name) == 1)
		{
			if (!(elm->value = strdup_u(*(environ + i))))
				exit(EXIT_FAILURE);
		}
		else if (!(elm->value = strdup_v(*(environ + i))))
			exit(EXIT_FAILURE);
		elm->next = *env;
		*env = elm;
		i++;
	}
	if (get_env_val(env, "PATH") == NULL)
		env_append(env, "PATH", "/bin:/usr/bin");
	env_append(env, "COLOR", "0");
}
