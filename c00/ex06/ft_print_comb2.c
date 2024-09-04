/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:56:49 by hboutale          #+#    #+#             */
/*   Updated: 2024/08/28 15:22:22 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnum(int n)
{
	char	c1;
	char	c2;

	c2 = (n % 10) + '0';
	c1 = (n / 10) % 10 + '0';
	ft_putchar(c1);
	ft_putchar(c2);
}

void	put_nums(int n, int m)
{
	putnum(n);
	ft_putchar(' ');
	putnum(m);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			put_nums(i, j);
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
