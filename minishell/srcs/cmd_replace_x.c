/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_replace_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:45:50 by anyo              #+#    #+#             */
/*   Updated: 2017/08/13 22:39:33 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	replace_tild() replaces the `~` character with $HOME path.
*/

void		replace_tild(t_env **env, char **command)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*(command + i))
	{
		if (**(command + i) == '~')
		{
			if (!(tmp = ft_strdup(*(command + i) + 1)))
				exit(EXIT_FAILURE);
			ft_strdel(&*(command + i));
			if (!(*(command + i) = ft_strjoin(get_env_val(env, "HOME"), tmp)))
				exit(EXIT_FAILURE);
			ft_strdel(&tmp);
		}
		i++;
	}
}

/*
**	replace_dot() replaces the `.` character with current directory path.
*/

void		replace_dot(char **command)
{
	char	*cwd;
	char	*tmp;
	int		i;

	i = 0;
	cwd = NULL;
	while (*(command + i))
	{
		if (ft_strncmp(*(command + i), ".", 1) == 0)
		{
			if (!(tmp = ft_strdup(*(command + i) + 1)))
				exit(EXIT_FAILURE);
			ft_strdel(&*(command + i));
			if (!(cwd = getcwd(NULL, 1024)))
				exit(EXIT_FAILURE);
			if (!(*(command + i) = ft_strjoin(cwd, tmp)))
				exit(EXIT_FAILURE);
			ft_strdel(&cwd);
			ft_strdel(&tmp);
		}
		i++;
	}
}

/*
**	replace_dotdot() replaces the `..` characters with ".." directory path.
*/

static char	*get_old_path(void)
{
	char	*cwd;
	char	*ret;
	int		j;

	if (!(cwd = getcwd(NULL, 1024)))
		return (NULL);
	j = ft_strlen(cwd);
	while (j > 0 && *(cwd + j) != '/')
		j--;
	if (!(ret = ft_strndup(cwd, j)))
		return (NULL);
	ft_strdel(&cwd);
	return (ret);
}

void		replace_dotdot(char **command)
{
	char	*dotdot;
	char	*tmp;
	int		i;

	i = 0;
	while (*(command + i))
	{
		if (ft_strncmp(*(command + i), "..", 2) == 0)
		{
			if (!(tmp = ft_strdup(*(command + i) + 2)))
				exit(EXIT_FAILURE);
			ft_strdel(&*(command + i));
			if (!(dotdot = get_old_path()))
				exit(EXIT_FAILURE);
			if (!(*(command + i) = ft_strjoin(dotdot, tmp)))
				exit(EXIT_FAILURE);
			ft_strdel(&dotdot);
			ft_strdel(&tmp);
		}
		i++;
	}
}
