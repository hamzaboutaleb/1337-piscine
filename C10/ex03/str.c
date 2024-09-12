/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:00 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 20:23:59 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_perror(char *filename, char *message)
{
	int	j;

	j = 0;
	ft_putstr("ft_hexdump: ", 0);
	ft_putstr(filename, 0);
	ft_putstr(message, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_char(char *s, int space)
{
	if (space == 1)
		ft_putchar(' ');
	ft_putstr(" |", 0);
	while (*s)
	{
		if (*s >= ' ' && *s < 127)
			ft_putchar(*s);
		else
			ft_putchar('.');
		s++;
	}
	ft_putchar('|');
}
