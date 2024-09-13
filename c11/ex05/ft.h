/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:52 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/12 14:40:04 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_printnbr(int nbr);
int		ft_atoi(char *str);
void	ft_add(int n1, int n2);
void	ft_sub(int n1, int n2);
void	ft_div(int n1, int n2);
void	ft_mul(int n1, int n2);
void	ft_mod(int n1, int n2);
#endif
