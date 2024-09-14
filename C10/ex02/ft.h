/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:56:13 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 11:52:56 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_args
{
	char		*pgr_name;
	int			c_flag;
	int			offset;
	char		**files;
	int			count_files;
}				t_args;
int				ft_atoi(char *str);
void			ft_print(char *s);
int				is_number(char *s);
int				ft_strcmp(char *s1, char *s2);
unsigned int	file_length(char *filename);