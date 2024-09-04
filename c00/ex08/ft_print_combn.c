/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08ft_print_combn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:31:05 by hboutale          #+#    #+#             */
/*   Updated: 2024/08/28 15:26:34 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_list_num(char store[9], int k, int is_last, char i)
{
	int	j;

	j = 0;
	while (j < k)
	{
		ft_putchar(store[j]);
		j++;
	}
	ft_putchar(i);
	if (is_last == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	print_combn_rec(char store[9], int k, int depth, char max)
{
	char	i;
	int		is_last;

	i = store[k - 1] + 1;
	if (depth == 1)
	{
		while (i <= '9')
		{
			is_last = 1;
			if (max != store[0])
			{
				is_last = 0;
			}
			put_list_num(store, k, is_last, i++);
		}
		return ;
	}
	else if (depth > 1)
	{
		while (i <= '9')
		{
			store[k] = i++;
			print_combn_rec(store, k + 1, depth - 1, max);
		}
	}
}

void	print_n1(void)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		ft_putchar(i + '0');
		if (i != 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		k;
	char	store[9];
	char	i;

	if (n == 1)
	{
		print_n1();
		return ;
	}
	k = 0;
	i = '0';
	while (i <= 10 - n + '0')
	{
		store[k] = i;
		print_combn_rec(store, k + 1, n - 1, 10 - n + '0');
		i++;
	}
}
