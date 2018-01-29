/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:49:30 by anyo              #+#    #+#             */
/*   Updated: 2017/06/01 20:08:47 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	format_and_join() is just here because of the norm. (:
**	return value:
**		NULL - ERROR! malloc() or time()
**		The formatted date - OK!
*/

static char	*format_and_join(time_t date, time_t current_date, t_tdata data)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char))))
		return (NULL);
	if (!(ret = ft_strjoin(ret, data.month)))
		return (NULL);
	if (!(ret = ft_strjoin(ret, " ")))
		return (NULL);
	if (!(ret = ft_strjoin(ret, data.day)))
		return (NULL);
	if (!(ret = ft_strjoin(ret, " ")))
		return (NULL);
	if (current_date - date > SIX_MONTHS)
	{
		if (!(ret = ft_strjoin(ret, " ")))
			return (NULL);
		if (!(ret = ft_strjoin(ret, data.year)))
			return (NULL);
	}
	else
	{
		if (!(ret = ft_strjoin(ret, data.hour)))
			return (NULL);
	}
	return (ret);
}

/*
**	format_date() returns the date that returns ctime(), formatted
**	as ls(1) does.
**	return value:
**		NULL - ERROR! malloc(), time() or ctime()
**		The formatted date - OK!
*/

char		*format_date(time_t date)
{
	time_t	current_date;
	char	*tmp;
	t_tdata	data;

	if ((current_date = time(NULL)) == -1)
		return (NULL);
	if (!(tmp = ft_strdup(ctime(&date))))
		return (NULL);
	tmp += 4;
	ft_strncpy(data.month, tmp, 3);
	data.month[3] = '\0';
	tmp += 4;
	ft_strncpy(data.day, tmp, 2);
	data.day[2] = '\0';
	tmp += 3;
	ft_strncpy(data.hour, tmp, 5);
	data.hour[5] = '\0';
	tmp += 9;
	ft_strncpy(data.year, tmp, 4);
	data.year[4] = '\0';
	free(tmp -= 20);
	return (format_and_join(date, current_date, data));
}
