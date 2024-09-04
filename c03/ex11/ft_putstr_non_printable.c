/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:03:46 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/04 17:43:05 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(unsigned char n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hexa[n / 16]);
	ft_putchar(hexa[n % 16]);
}

void	ft_print(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (c >= ' ' && c < 127)
		{
			ft_putchar(c);
		}
		else
		{
			ft_hex(c);
		}
		str++;
	}
}
