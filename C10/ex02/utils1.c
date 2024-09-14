/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:56:55 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/14 14:58:35 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	perror_offset(char *pgr, char *offset)
{
	ft_rprint(pgr);
	ft_rprint(": illegal offset --");
	ft_rprint(offset);
	ft_rprint("\n");
}

void	perror_nofile(char *pgr, char *file)
{
	ft_rprint(pgr);
	ft_rprint(": ");
	ft_rprint(file);
	ft_rprint(": No such file or directory\n");
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
