/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:26:48 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/03 20:29:53 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i >= 1)
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i--;
	}
}
