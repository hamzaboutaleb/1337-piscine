/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:14:25 by hboutale          #+#    #+#             */
/*   Updated: 2024/08/28 09:20:27 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	ne;
	char	p;

	ne = 'N';
	p = 'P';
	if (n >= 0)
	{
		write(1, &p, 1);
	}
	else
	{
		write(1, &ne, 1);
	}
}
