/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:33:27 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/03 20:56:47 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **arr, int i, int j)
{
	char	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	sort(char **arr, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
				ft_swap(arr, j, j + 1);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	sort(av + 1, ac - 1);
	while (i < ac)
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i++;
	}
}
