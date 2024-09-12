/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:28 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 19:48:28 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_args
{
	int				c_flag;
	char			**files;
	unsigned int	start;
	int				argc;
}					t_args;

// hex
void				char_hex(unsigned char c);
void				print_hex(char buffer[17], t_args *args);
void				ft_printnbr(int nbr, char *base);
void				pad_number(int number, int pad);
// str
void				ft_putchar(char c);
void				ft_putstr(char *s, int end);
int					ft_strlen(char *s);
void				ft_perror(char *filename, char *message);
int					ft_strcmp(char *s1, char *s2);
void				print_char(char *s, int space);