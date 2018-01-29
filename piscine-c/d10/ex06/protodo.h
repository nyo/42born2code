/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protodo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:42:43 by anyo              #+#    #+#             */
/*   Updated: 2016/08/24 13:45:59 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTODO_H
# define PROTODO_H

# include <unistd.h>

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mul(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_is_nb(char *str);
int		ft_is_op(char *str);

#endif
