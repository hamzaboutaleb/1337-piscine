/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:05:01 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/04 20:43:21 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	if (*str == '\0' && *to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
