/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:13:56 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/05 18:05:04 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	strs_len(char **strs, int size)
{
	int				i;
	unsigned int	count;
	int				j;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		count += j;
		i++;
	}
	return (count);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print(char **strs, char *res, char *sep, int size)
{
	int				i;
	unsigned int	k;
	int				j;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				res[k++] = sep[j++];
		}
		i++;
	}
	res[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*res;
	unsigned int	len;

	if (size == 0)
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	len = ft_strlen(sep) * (size - 1) + strs_len(strs, size);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_print(strs, res, sep, size);
	return (res);
}
