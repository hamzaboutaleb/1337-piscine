/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:27 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 17:11:17 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	open_file(t_args *args)
{
	int	fd;

	fd = open(args->files[args->i], O_RDONLY);
	args->i++;
	return (fd);
}

void	print_buffer(char *buffer, t_args *args)
{
	pad_number(args->start, args->pad);
	if (args->c_flag)
		ft_putchar(' ');
	print_hex(buffer, args);
	if (args->c_flag)
		print_char(buffer, args->c_flag);
	ft_putchar('\n');
}

int	fill_buffer(int fd, char buffer[17], int *k)
{
	char	c;

	while (*k < 16 && read(fd, &c, 1) && c != 0)
	{
		buffer[(*k)++] = c;
	}
	if (*k == 16)
	{
		buffer[(*k)] = '\0';
		*k = 0;
		return (1);
	}
	else
		return (0);
}

int	buffer_help(int *fd, t_args *args, char buffer[17], int i)
{
	if (args->i < args->argc)
	{
		*fd = open_file(args);
	}
	else
	{
		buffer[i] = '\0';
		args->i++;
		return (0);
	}
	return (1);
}

void	cmp_help(char prev_buffer[17], char buffer[17], t_args *args, int *is_p)
{
	if (ft_strcmp(prev_buffer, buffer) == 0)
	{
		args->start += 16;
		if (*is_p == 0)
			ft_putstr("*", 1);
		*is_p = 1;
	}
	else
	{
		*is_p = 0;
		print_buffer(buffer, args);
	}
}
