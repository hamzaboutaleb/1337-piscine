/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:03:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/12 22:02:06 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

void	perror(char *name)
{
	int	j;

	j = 0;
	write(2, "ft_tail: ", 9);
	while (name[j])
		write(2, &name[j++], 1);
	write(2, ": No such file or directory\n", 28);
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
			is_first = 0;
			print_names(argv[i]);
		}
		if (fd >= 0)
			show_file_content(i, fd, argv);
		else
			perror(argv[i]);
		close(fd);
		i++;
	}
}
