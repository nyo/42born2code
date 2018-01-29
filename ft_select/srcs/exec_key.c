/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:06:05 by anyo              #+#    #+#             */
/*   Updated: 2017/09/27 23:01:47 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	-------------------------------------------------------------------------- +
**	exec_key() calls the function corresponding to the key pressed.
**	It returns EXIT_FAILURE on failure, EXIT_SUCCESS on success.
**	-------------------------------------------------------------------------- +
*/

int	exec_key(t_files **head, char **ds_mem, char *key)
{
	static int	(*press_stuff[])(t_files **, char *) = {
	&press_unselect_all, &press_select_all,
	&press_arrow_down, &press_arrow_up,
	&press_delete, &press_return,
	&press_color, &press_space,
	&press_check,
	NULL};
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if (!(*ds_mem = ft_strjoin_free(*ds_mem, key, 1)))
		return (EXIT_FAILURE);
	if (*(key + 0) == KEY_RESIZE && *(key + 1) == KEY_END)
		clean_screen();
	else if (*(key + 0) == KEY_ESCAPE && *(key + 1) == KEY_END)
		clean_exit(head, g_mem);
	else if (ft_isalnum(*(key + 0)) && *(key + 1) == KEY_END)
		ret = press_ds(head, ds_mem, key);
	else
		while (press_stuff[i] && (ret = press_stuff[i](head, key)) == 0)
			i++;
	return (ret == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
