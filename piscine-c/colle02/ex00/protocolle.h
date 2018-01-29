/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocolle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:55:53 by anyo              #+#    #+#             */
/*   Updated: 2016/08/21 20:36:48 by bin0me           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOLLE_H
# define PROTOCOLLE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

int		ft_check_char(char *str, char *s1, char *s2);
int		ft_check_rect(char *str);
int		ft_check_size(char *str);
int		ft_height(char *str);
int		ft_is_colle(char *str, char *l1, char *l2);
char	*ft_keep_e(char *str);
char	*ft_keep_s(char *str);
char	*ft_s_keep_e(char *str);
char	*ft_s_keep_s(char *str);
void	ft_print_sbracket(char *str, int a, int b);
void	ft_wich_colle(char *l1, char *l2);
int		ft_width(char *str);

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
