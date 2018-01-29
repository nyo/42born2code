/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:49:21 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 22:21:41 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	try_cmd_path() tries every available path for `cmd` and returns
**	the existing one so we can execute cmd.
**	return value:
**	-	the full string containing the correct path and binary
**	-	if no correct path has been found, returns a "nf" (notfound) string
**	-	NULL, if malloc() failed somewhere
*/

char	*try_cmd_path(char *path, char *cmd)
{
	char	**path_tab;
	char	*full_path;
	char	*tmp;
	int		i;

	i = -1;
	if (!(path_tab = ft_strsplit(path, ':')))
		return (NULL);
	while (*(path_tab + ++i))
	{
		if (!(tmp = ft_strjoin(*(path_tab + i), "/")))
			return (NULL);
		if (!(full_path = ft_strjoin(tmp, cmd)))
			return (NULL);
		ft_strdel(&tmp);
		if (access(full_path, X_OK) == 0)
		{
			ft_arrfree(path_tab);
			return (full_path);
		}
		ft_strdel(&full_path);
	}
	ft_strdel(&full_path);
	ft_arrfree(path_tab);
	return (ft_strdup("nf"));
}

/*
**	get_cmd_path() finds the string containing the path in the environ.
**	return value:
**	-	the formatted string containing the correct path and binary
**	-	NULL, if try_cmd_path() failed
**	note that it returns a string even if the right one has not been found.
*/

char	*get_cmd_path(t_env **env, char **command)
{
	t_env	*elm;
	char	*cmd;

	elm = *env;
	while (elm)
	{
		if (ft_strncmp(elm->name, "PATH\0", 5) == 0)
			break ;
		elm = elm->next;
	}
	if (!(cmd = try_cmd_path(elm->value, *command)))
		return (NULL);
	return (cmd);
}
