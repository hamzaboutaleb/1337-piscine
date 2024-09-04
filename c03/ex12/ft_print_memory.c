/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:42:27 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/04 17:56:52 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_hex(unsigned long int n, char *str, int is_char)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (is_char == 1)
	{
		str[i++] = hex[(unsigned char) n % 16];
		str[i++] = hex[(unsigned char) n / 16];
		str[i] = '\0';
		return (str);
	}
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n != 0)
	{
		str[i++] = hex[n % 16];
		n /= 16;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_hex(char *hex, int pad, char c, int add_dbl_p)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (hex[count])
		count++;
	while (i < pad - count)
	{
		ft_putchar(c);
		i++;
	}
	count--;
	while (count >= 0)
		ft_putchar(hex[count--]);
	if (add_dbl_p)
		ft_putchar(':');
}

void	ft_print_ascii(unsigned int *i, char *str, unsigned int size, char *hex)
{
	unsigned int	end;

	end = *i + 16;
	while (*i < end)
	{
		if (*i % 2 == 0)
			ft_putchar(' ');
		if (*i < size)
			ft_print_hex(ft_hex((unsigned char)str[*i], hex, 1), 2, '0', 0);
		else
			ft_print_hex("", 2, ' ', 0);
		(*i)++;
	}
	ft_putchar(' ');
	*i = *i - 16;
	while (*i < end && *i < size)
	{
		if (*i < size && str[*i] >= ' ' && str[*i] < 127)
			ft_putchar(str[*i]);
		else if (*i < size)
			ft_putchar('.');
		else
			ft_putchar(' ');
		(*i)++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long int	start;
	char				*str;
	char				hex[17];
	unsigned int		i;

	if (size == 0)
		return (addr);
	i = 0;
	start = (unsigned long int) addr;
	str = (char *) addr;
	while (i < size)
	{
		ft_print_hex(ft_hex(start + i, hex, 0), 16, '0', 1);
		ft_print_ascii(&i, str, size, hex);
		ft_putchar('\n');
	}
	return (addr);
}
