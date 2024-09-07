/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:03:41 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/07 09:13:02 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *str)
{
	int	lookup[128];
	int	i;

	i = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (i < 128)
		lookup[i++] = 0;
	while (*str)
	{
		if (*str < ' ' || *str == 127)
			return (0);
		if (*str == '-' || *str == '+' || lookup[(int)*str] == 1)
			return (0);
		lookup[(int)*str] = 1;
		str++;
	}
	return (1);
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

void	ft_putnbr_base(int nbr, char *base)
{
	if (is_valid_base(base) == 0)
		return ;
	ft_printnbr(nbr, base);
}
