/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:47:26 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/09 11:23:52 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_println(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	while (par[i])
	{
		ft_println(par[i].str);
		ft_println(par[i].size);
		ft_println(par[i].copy);
		i++;
	}
}
