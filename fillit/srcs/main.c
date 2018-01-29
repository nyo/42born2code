/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:40:24 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/06 16:17:19 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_lst_pushback(t_piece *begin_list, t_piece *new)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	if (begin_list)
		begin_list->next = new;
}

static int		count_pieces(char **pieces)
{
	int		i;

	i = 0;
	while (pieces[i])
		i++;
	return (i);
}

static void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static t_piece	*create_lst(char **pieces)
{
	int			i;
	t_piece		*lst;

	i = 0;
	lst = new_piece('A' + i, pieces[i]);
	i++;
	while (pieces[i])
	{
		ft_lst_pushback(lst, new_piece('A' + i, pieces[i]));
		i++;
	}
	return (lst);
}

int				main(int ac, char **av)
{
	int					size;
	t_piece				*lst;
	unsigned short int	*map;
	char				*file;
	char				**allpieces;

	allpieces = NULL;
	if (ac == 2)
	{
		file = file_to_str(av[1]);
		if (!file || !(allpieces = check_file(file)))
		{
			ft_putendl("error");
			exit(EXIT_SUCCESS);
		}
		size = ft_sqrt(count_pieces(allpieces) * 4) - 1;
		lst = create_lst(allpieces);
		free_tab(allpieces);
		while ((map = init_map()) && !(isplace_piece(map, lst, ++size)))
			free(map);
		show_result(size, lst);
		exit(EXIT_SUCCESS);
	}
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
