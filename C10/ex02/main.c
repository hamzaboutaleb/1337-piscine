/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:03:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 20:33:28 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += ((int)str[i] - '0');
		i++;
	}
	return (number);
}

void	print_names(char *name)
{
	int	i;

	i = 0;
	write(1, "==> ", 4);
	while (name[i])
	{
		write(1, &name[i++], 1);
	}
	write(1, " <==\n", 5);
}

int	size_file(char *filename)
{
	int		fd;
	char	buffer;
	int		size;

	size = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &buffer, 1))
		size++;
	close(fd);
	return (size);
}

void	show_file_content(int i, int fd, char **argv)
{
	char	buffer;
	int		offset;
	int		readed;
	int		size;

	size = size_file(argv[i]);
	readed = 0;
	offset = ft_atoi(argv[2]);
	if (argv[2][0] == '+')
	{
		while (readed != offset - 1)
			readed += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
	else
	{
		while (readed < (size - offset))
			readed += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	int	is_first;
	int	j;

	i = 3;
	is_first = 1;
	if (argc < 4)
		return (1);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (argc > 4 && fd >= 0)
		{
			if (is_first == 0)
				write(1, "\n", 1);
			else
				is_first = 0;
			print_names(argv[i]);
		}
		if (fd >= 0)
			show_file_content(i, fd, argv);
		else
		{
			j = 0;
			write(2, "ft_tail: ", 9);
			while (argv[i][j])
				write(2, &argv[i][j++], 1);
			write(2, ": No such file or directory\n", 28);
		}
		close(fd);
		i++;
	}
	return (0);
}
