/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:23:42 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/13 10:29:33 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, int end)
{
	while (*s)
		write(1, s++, 1);
	if (end == 1)
		write(1, "\n", 1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				count;
	unsigned int	i;

	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

int	fill_buffer(int fd, char buffer[17])
{
	int		k;
	char	c;

	k = 0;
	while (k < 16 && read(fd, &c, 1) && c != 0)
	{
		buffer[k++] = c;
	}
	buffer[k] = '\0';
	if (k == 0)
		return (0);
	return (1);
}
