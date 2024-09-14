/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:56:04 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 15:03:31 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	file_length(char *filename)
{
	unsigned int	count;
	char			buffer[1024];
	int				bytes;
	int				fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		count += bytes;
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	return (count);
}

void	print_n_file_content(int fd, unsigned int offset, unsigned int size)
{
	char			*buffer;
	unsigned int	i;
	char			c;

	buffer = (char *)malloc(sizeof(char) * offset);
	if (offset > size)
	{
		read(fd, buffer, size);
		write(1, buffer, size);
		free(buffer);
		return ;
	}
	i = 0;
	while (i < (size - offset) && read(fd, &c, 1))
	{
		i++;
	}
	read(fd, buffer, offset);
	write(1, buffer, offset);
	free(buffer);
}
