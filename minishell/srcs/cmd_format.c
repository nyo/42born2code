/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:22:05 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 21:05:42 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	nb_of_words() simply counts the number of words in the entered string.
**	return value:
**	-	the number of words
*/

static int	nb_of_words(char *raw_cmd)
{
	int	nb;
	int s;
	int	i;

	i = 0;
	s = 0;
	nb = 0;
	while (*(raw_cmd + i))
	{
		if (s == 1 && ISBLANK(*(raw_cmd + i)))
			s = 0;
		if (s == 0 && !(ISBLANK(*(raw_cmd + i))))
		{
			s = 1;
			nb++;
		}
		i++;
	}
	return (nb);
}

/*
**	my_strdup_n() removes blank chars in the entered string,
**	then copies it to a new perfectly sized one.
**	return value:
**	-	the new string we want in the cmd array
**	-	NULL, if malloc() fails
*/

static char	*my_strdup_n(char *raw_cmd, int n)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ISBLANK(*(raw_cmd + i)))
		i++;
	while (n-- > 0)
	{
		while (!(ISBLANK(*(raw_cmd + i))))
			i++;
		while (ISBLANK(*(raw_cmd + i)))
			i++;
	}
	len = i;
	while (*(raw_cmd + len) && !(ISBLANK(*(raw_cmd + len))))
		len++;
	if (!(ret = ft_strnew(len - i)))
		return (NULL);
	while (*(raw_cmd + i) && !(ISBLANK(*(raw_cmd + i))))
		*(ret + j++) = *(raw_cmd + i++);
	*(ret + j) = '\0';
	return (ret);
}

/*
**	cmd_format() takes the raw command string (input),
**	and splits it into an array of strings.
**	return value:
**	-	an array of strings containing all command elements
**	-	NULL, if malloc() failed somewhere...
*/

char		**cmd_format(t_env **env, char *raw_cmd)
{
	char	**formatted_cmd;
	int		size;
	int		i;

	i = 0;
	size = nb_of_words(raw_cmd);
	if (!(formatted_cmd = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(*(formatted_cmd + i) = my_strdup_n(raw_cmd, i)))
			return (NULL);
		i++;
	}
	*(formatted_cmd + i) = NULL;
	replace_tild(env, formatted_cmd);
	replace_dotdot(formatted_cmd);
	replace_dot(formatted_cmd);
	return (formatted_cmd);
}
