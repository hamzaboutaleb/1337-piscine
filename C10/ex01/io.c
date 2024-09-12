/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:56 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 10:48:57 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print(char *s, int end)
{
	while (*s)
		write(1, s++, 1);
	if (end)
		write(1, "\n", 1);
}

void	ft_perror(char *program_name, char *filename)
{
	ft_print(basename(program_name), 0);
	ft_print(": ", 0);
	ft_print(basename(filename), 0);
	ft_print(": No such file or directory", 1);
}

void	ft_print_content(int fp)
{
	char	buffer[100];
	int		bytes;

	bytes = read(fp, buffer, 99);
	while (bytes != 0)
	{
		buffer[bytes] = '\0';
		ft_print(buffer, 0);
		bytes = read(fp, buffer, 99);
	}
}

void	read_files(char **files, int size)
{
	int	fp;
	int	i;

	i = 1;
	while (i < size)
	{
		fp = open(files[i], O_RDONLY);
		if (fp < 0)
			ft_perror(files[0], files[i]);
		else
		{
			ft_print_content(fp);
			close(fp);
		}
		i++;
	}
}

void	interactive_mode(void)
{
	char	buffer[BUFFER_SIZE];
	int		bytes;

	bytes = read(0, &buffer, BUFFER_SIZE - 1);
	while (bytes != 0)
	{
		buffer[bytes] = '\0';
		ft_print((char *)buffer, 0);
		bytes = read(0, &buffer, BUFFER_SIZE - 1);
	}
}
