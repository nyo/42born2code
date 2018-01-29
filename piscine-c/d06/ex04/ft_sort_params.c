/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 23:02:04 by anyo              #+#    #+#             */
/*   Updated: 2016/08/16 15:27:27 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}

void	ft_display(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i += 1;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 1;
	while (j != 0)
	{
		j = 0;
		i = 1;
		while (i < (argc - 1))
		{
			if (ft_strcmp(argv[i], argv[i + 1]) >= 0)
			{
				tmp = argv[i + 1];
				argv[i + 1] = &*argv[i];
				argv[i] = tmp;
				j += 1;
			}
			i += 1;
		}
	}
	ft_display(argc, &*argv);
	return (0);
}
