/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:31:09 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/12 21:54:18 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *s, int end)
{
	while (*s)
		write(1, s++, 1);
	if (end)
		write(1, "\n", 1);
}

void	print_content(int fp)
{
	char	buffer[100];
	int		bytes;

	bytes = read(fp, buffer, 99);
	while (bytes != 0)
	{
		buffer[bytes] = '\0';
		ft_putstr(buffer, 0);
		bytes = read(fp, buffer, 99);
	}
}

void	print_file_content(char *filename)
{
	int	fp;

	fp = open(filename, O_RDONLY);
	if (fp < 0)
	{
		ft_putstr("Cannot read file.", 1);
		return ;
	}
	print_content(fp);
	close(fp);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.", 1);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.", 1);
		return (1);
	}
	print_file_content(argv[1]);
	return (0);
}
