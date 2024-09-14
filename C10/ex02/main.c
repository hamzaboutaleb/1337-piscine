/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:03:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 13:49:37 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// ft_tail -c a
// ft_tail -c 55

void	perror_offset(char *pgr, char *offset)
{
	ft_print(pgr);
	ft_print(": illegal offset --");
	ft_print(offset);
	ft_print("\n");
}

void	perror_nofile(char *pgr, char *file)
{
	ft_print(pgr);
	ft_print(": ");
	ft_print(file);
	ft_print(": No such file or directory\n");
}

void	ft_header_file(char *filename)
{
	static unsigned int	count = 0;

	if (count != 0)
		ft_print("\n");
	ft_print("==> ");
	ft_print(filename);
	ft_print(" <==");
	ft_print("\n");
	count++;
}

int	init_args(t_args *args, int ac, char **av)
{
	int		i;
	char	*s;

	i = 1;
	args->pgr_name = basename(av[0]);
	while (i < ac)
	{
		s = av[i];
		if (i == 1 && ft_strcmp(s, "-c") == 0)
		{
			args->c_flag = 1;
		}
		else if (i == 2)
		{
			if (is_number(s))
				args->offset = ft_atoi(s);
			else
			{
				perror_offset(args->pgr_name, s);
				return (0);
			}
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

void	interactive_mode(void)
{
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
	if (!init_args(&args, argc, argv))
	{
		return (0);
	}
	if (args.files)
		batch_mode(&args);
	else
		interactive_mode();
}
