/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:54:07 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/05 21:51:31 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(int nbr, int base);
int	ft_strlen(char *str);

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

char	*ft_putnbr(int nbr, char *base, int blen)
{
	char	*res;
	int		k;
	int		sign;

	sign = 1;
	k = ft_nbrlen(nbr, blen) - 1;
	res = (char *)malloc(k + 1);
	res[k--] = '\0';
	if (res == NULL)
		return (NULL);
	if (nbr < 0)
		sign = -1;
	if (nbr <= 0)
	{
		res[k--] = base[-(nbr % blen)];
		nbr = (nbr / blen) * -1;
	}
	while (nbr != 0)
	{
		res[k--] = base[nbr % blen];
		nbr /= blen;
	}
	if (sign == -1)
		res[k--] = '-';
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	sign;
	int	n;

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (is_valid_base(base_from) == 0 || is_valid_base(base_to) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_putnbr(nb, base_to, ft_strlen(base_to)));
}
