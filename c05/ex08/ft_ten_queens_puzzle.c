/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_aueens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:37:27 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/04 13:43:30 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int sol[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = sol[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid_place(int sol[10], int row, int col)
{
	int	left;
	int	right;

	left = col - 1;
	right = col + 1;
	while (row >= 0)
	{
		if (sol[row] == col || sol[row] == left || sol[row] == right)
			return (0);
		left--;
		right++;
		row--;
	}
	return (1);
}

void	ft_ten_queens(int sol[10], int row, int *count)
{
	int	i;

	if (row == 10)
	{
		(*count)++;
		ft_print(sol);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (is_valid_place(sol, row - 1, i))
		{
			sol[row] = i;
			ft_ten_queens(sol, row + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	sol[10];

	count = 0;
	while (count < 10)
		sol[count++] = -1;
	count = 0;
	ft_ten_queens(sol, 0, &count);
	return (count);
}
