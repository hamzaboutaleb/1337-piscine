/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:19 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/13 19:43:10 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

int	ft_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	size = ft_len(tab);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				swap(tab, j, j + 1);
			}
			j++;
		}
		i++;
	}
}
