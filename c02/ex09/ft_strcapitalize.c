/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:25:04 by hboutale          #+#    #+#             */
/*   Updated: 2024/08/30 08:38:17 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 'A');
	}
	return (c);
}

char	ft_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 'a');
	}
	return (c);
}

int	ft_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_alpha_numeric(char c)
{
	if (ft_alpha(c) == 1 || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (i == 0)
		{
			str[i] = ft_upper(c);
		}
		else if (ft_alpha_numeric(str[i - 1]) == 0)
		{
			str[i] = ft_upper(c);
		}
		else
		{
			str[i] = ft_lower(c);
		}
		i++;
	}
	return (str);
}
