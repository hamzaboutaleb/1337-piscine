/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:28 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 17:09:11 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

typedef struct s_buffer
{
	char			buffer[17];
	int				i;
}					t_buffer;

typedef struct s_args
{
	int				c_flag;
	char			**files;
	unsigned int	start;
	int				argc;
	int				pad;
	int				i;
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
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
int					fill_buffer(int fd, char buffer[17], int *k);
void				ft_rputstr(char *s, int end);
void				cmp_help(char prev_buffer[17], char buffer[17],
						t_args *args, int *is_p);
int					buffer_help(int *fd, t_args *args, char buffer[17], int i);
int					fill_buffer(int fd, char buffer[17], int *k);
void				print_buffer(char *buffer, t_args *args);
int					open_file(t_args *args);