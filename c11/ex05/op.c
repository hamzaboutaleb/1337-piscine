/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:06 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/12 14:32:32 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_add(int n1, int n2)
{
	int	res;

	res = n1 + n2;
	ft_printnbr(res);
}

void	ft_sub(int n1, int n2)
{
	int	res;

	res = n1 - n2;
	ft_printnbr(res);
}

void	ft_div(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_printnbr(n1 / n2);
}

void	ft_mul(int n1, int n2)
{
	ft_printnbr(n1 * n2);
}

void	ft_mod(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_printnbr(n1 % n2);
}
