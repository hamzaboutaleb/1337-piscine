/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:33:56 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/03 12:50:30 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *str)
{
	int	lookup[128];
	int	i;

	i = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (i < 128)
		lookup[i++] = 0;
	while (*str)
	{
		if (*str < ' ' || *str == 127)
			return (0);
		if (*str == '-' || *str == '+' || lookup[(int)*str] == 1)
			return (0);
		lookup[(int)*str] = 1;
		str++;
	}
	return (1);
}

int	index_of(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	sign;
	int	n;

	if (is_valid_base(base) == 0)
		return (0);
	sign = 1;
	i = 0;
	res = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		n = index_of(base, str[i++]);
		if (n == -1)
			break ;
		res = res * ft_strlen(base) + n;
	}
	return (res * sign);
}
