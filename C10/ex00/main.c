/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:31:09 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 17:13:55 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void	ft_putstr(int fd, char *s)
{
	while (*s)
		write(fd, s++, 1);
}

void	display_file(char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "Cannot read file.\n");
		return ;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr(2, "File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (1);
	}
	display_file(argv[1]);
	return (0);
}
