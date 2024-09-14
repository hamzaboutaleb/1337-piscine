/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:28 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 17:08:41 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_dump(int fd, t_args *args)
{
	char	buffer[17];
	char	prev_buffer[17];
	int		is_printed;
	int		i;

	is_printed = 0;
	i = 0;
	prev_buffer[0] = '\0';
	while (args->i <= args->argc)
	{
		while (fill_buffer(fd, buffer, &i) == 0)
		{
			if (buffer_help(&fd, args, buffer, i) == 0)
				break ;
		}
		cmp_help(prev_buffer, buffer, args, &is_printed);
		ft_strlcpy(prev_buffer, buffer, 17);
		i = 0;
	}
}

void	test_open_file(t_args *args)
{
	int	i;
	int	fd;
	int	count;

	i = 0;
	count = 0;
	while (i < args->argc)
	{
		fd = open(args->files[i], O_RDONLY);
		if (fd < 0)
		{
			count++;
			ft_perror(args->files[i], ": No such file or directory");
		}
		else
			close(fd);
		i++;
	}
	if (count == args->argc)
		ft_perror(args->files[i - 1], ": Bad file descriptor");
}

void	batch_mode(t_args *args)
{
	int	fd;

	test_open_file(args);
	fd = open_file(args);
	while (fd < 0 && args->i < args->argc)
	{
		fd = open_file(args);
	}
	if (fd > 0)
	{
		ft_dump(fd, args);
		pad_number(args->start, args->pad);
		ft_putchar('\n');
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
	if (args->c_flag)
		args->pad = 8;
	else
		args->pad = 7;
}

int	main(int argc, char **argv)
{
	t_args	args;

	args.c_flag = 0;
	args.files = (void *)0;
	args.start = 0;
	args.argc = 0;
	args.i = 0;
	parse_args(&args, argc, argv);
	if (!args.files)
	{
		ft_dump(0, &args);
		pad_number(args.start, args.pad);
		ft_putchar('\n');
	}
	else
	{
		batch_mode(&args);
	}
}
