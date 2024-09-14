/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:03:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 14:58:42 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	init_args(t_args *args, int ac, char **av)
{
	int		i;
	char	*s;

	i = 1;
	while (i < ac)
	{
		s = av[i];
		if (i == 1 && ft_strcmp(s, "-c") == 0)
			args->c_flag = 1;
		else if (i == 2)
		{
			if (is_number(s))
				args->offset = ft_atoi(s);
			else
				return (0);
		}
		else
		{
			args->files = av + i;
			args->count_files = ac - i;
			return (1);
		}
		i++;
	}
	return (1);
}

void	ft_write(unsigned int count, unsigned int offset, char *buffer)
{
	unsigned int	start;
	unsigned int	nchar;
	unsigned int	i;

	start = 0;
	nchar = count;
	if (count >= offset)
	{
		start = count % offset;
		nchar = offset;
	}
	i = 0;
	while (i < nchar)
	{
		ft_putchar(buffer[(start + i) % offset]);
		i++;
	}
}

void	interactive_mode(unsigned int offset)
{
	char			*buffer;
	char			c;
	unsigned int	count;

	buffer = (char *)malloc(sizeof(char) * (offset));
	count = 0;
	while (read(0, &c, 1) && c != '\0')
	{
		buffer[count % offset] = c;
		count++;
	}
	ft_write(count, offset, buffer);
	free(buffer);
}

void	batch_mode(t_args *args)
{
	int		i;
	int		fd;
	char	*filename;

	i = 0;
	while (i < args->count_files)
	{
		filename = args->files[i];
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			perror_nofile(args->pgr_name, args->files[i]);
		else
		{
			if (args->count_files != 1)
				ft_header_file(filename);
			print_n_file_content(fd, args->offset, file_length(filename));
			close(fd);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	args.c_flag = 0;
	args.offset = -1;
	args.files = NULL;
	args.count_files = 0;
	args.pgr_name = basename(argv[0]);
	if (!init_args(&args, argc, argv))
	{
		perror_offset(args.pgr_name, argv[2]);
		return (0);
	}
	if (args.files)
		batch_mode(&args);
	else
		interactive_mode(args.offset);
}
