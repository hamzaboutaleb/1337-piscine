/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:28 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/13 09:07:38 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_buffer(char *buffer, t_args *args, int pad)
{
	pad_number(args->start, pad);
	if (args->c_flag)
		ft_putchar(' ');
	print_hex(buffer, args);
	if (args->c_flag)
		print_char(buffer, args->c_flag);
	ft_putchar('\n');
}

void	ft_dump(int fd, t_args *args)
{
	char	buffer[17];
	int		pad;
	char	c;
	int		k;

	if (args->argc)
		pad = 8;
	else
		pad = 7;
	while (1)
	{
		k = 0;
		while (k < 16 && read(fd, &c, 1) && c != 0)
		{
			buffer[k++] = c;
		}
		buffer[k] = '\0';
		if (k == 0)
			break ;
		print_buffer(buffer, args, pad);
	}
	pad_number(args->start, pad);
	ft_putchar('\n');
}

void	batch_mode(t_args *args)
{
	int	i;
	int	fd;

	i = 0;
	while (i < args->argc)
	{
		fd = open(args->files[i], O_RDONLY);
		if (fd < 0)
		{
			ft_perror(args->files[i], ": No such file or directory");
			if (i == args->argc)
				ft_perror(args->files[i], ": Bad file descriptor");
		}
		else
			ft_dump(fd, args);
		i++;
	}
}

void	parse_args(t_args *args, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1 && ft_strcmp(argv[i], "-C") == 0)
			args->c_flag = 1;
		else
		{
			args->argc = argc - i;
			args->files = &argv[i];
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	args.c_flag = 0;
	args.files = (void *)0;
	args.start = 0;
	args.argc = 0;
	parse_args(&args, argc, argv);
	if (!args.files)
	{
		ft_dump(0, &args);
	}
	else
	{
		batch_mode(&args);
	}
}
