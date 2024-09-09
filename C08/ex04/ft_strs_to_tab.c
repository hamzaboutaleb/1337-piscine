/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:17:17 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/09 11:35:15 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		slen;
	char	*res;
	int		i;

	i = 0;
	slen = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * slen + 1);
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			k;
	int			i;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (i < ac)
	{
		res[k].size = ft_strlen(av[i]);
		res[k].str = av[i];
		res[k].copy = ft_strdup(av[i]);
		if (res[k].copy == NULL)
			return (NULL);
		k++;
		i++;
	}
	res[k].size = 0;
	res[k].str = 0;
	res[k].copy = 0;
	return (res);
}
