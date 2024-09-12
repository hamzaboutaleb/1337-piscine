/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:22:32 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 20:22:21 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	char_hex(unsigned char c)
{
	char			*hex;
	unsigned char	i;

	hex = "0123456789abcdef";
	i = c / 16;
	ft_putchar(hex[i]);
	i = c % 16;
	ft_putchar(hex[i]);
}

void	print_hex(char buffer[17], t_args *args)
{
	int	i;
	int	bufflen;
	int	k;

	k = 0;
	bufflen = ft_strlen((char *)buffer);
	i = 0;
	while (i < 16 * 2)
	{
		if (i == 16 && args->c_flag)
			ft_putchar(' ');
		if ((i + 1) % 2 == 1)
		{
			ft_putchar(' ');
		}
		else if (k < bufflen)
		{
			args->start++;
			char_hex(buffer[k++]);
		}
		else
			ft_putstr("  ", 0);
		i++;
	}
}

void	ft_printnbr(int nbr, char *base)
{
	int	blen;

	blen = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		if ((nbr / blen) * -1 > 0)
			ft_printnbr((nbr / blen) * -1, base);
		ft_printnbr(-(nbr % blen), base);
		return ;
	}
	if (nbr >= blen)
	{
		ft_printnbr(nbr / blen, base);
		ft_printnbr(nbr % blen, base);
	}
	else
		ft_putchar(base[nbr]);
}

void	pad_number(int number, int pad)
{
	int	len;
	int	i;
	int	n;

	n = number;
	i = 0;
	len = 0;
	while (number > 0)
	{
		len++;
		number /= 16;
	}
	while (i < pad - len)
	{
		write(1, "0", 1);
		i++;
	}
	if (n != 0)
		ft_printnbr(n, "0123456789abcdef");
}
