/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:06:44 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/05 11:10:44 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (NULL);
	res = (int *)malloc(sizeof(int) * (max - min));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		res[i++] = min;
		min++;
	}
	return (res);
}
