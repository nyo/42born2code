/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hist_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:54:59 by mate              #+#    #+#             */
/*   Updated: 2018/04/26 22:17:14 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*get_hist_path(void)
{
	struct passwd	*passwd;
	char			*tmp;
	char			*s;
	uid_t			uid;

	uid = getuid();
	if (!(passwd = getpwuid(uid)))
		return (ft_strdup(""));
	s = passwd->pw_name;
	if (!(tmp = ft_strjoin("/Users/", s)))
		return (ft_strdup(""));
	return (ft_strjoin_free(tmp, "/.42sh_history", 1));
}
