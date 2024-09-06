/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:50:53 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/05 21:51:00 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int nbr, int base)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;
	if (nbr == 0)
		return (2);
	while (nbr != 0)
	{
		count++;
		nbr /= base;
	}
	return (count + 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
