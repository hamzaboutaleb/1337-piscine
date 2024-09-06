/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:25:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/06 10:31:41 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	string_has(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && string_has(charset, str[i]))
			i++;
		if (str[i])
			res++;
		while (str[i] && !string_has(charset, str[i]))
			i++;
	}
	return (res);
}

char	*make_string(char *str, int start, int end)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = end - start;
	res = (char *)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		k;
	int		start;
	int		end;

	k = 0;
	i = 0;
	if (*str == '\0' || *charset == '\0')
		return (NULL);
	res = (char **)malloc(sizeof(char *) * count_words(str, charset) + 1);
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && string_has(charset, str[i]))
			i++;
		start = i;
		while (str[i] && !string_has(charset, str[i]))
			i++;
		end = i;
		res[k++] = make_string(str, start, end);
	}
	res[k] = make_string(str, i, i + 1);
	return (res);
}
