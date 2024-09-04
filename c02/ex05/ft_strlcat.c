/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:22:45 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/01 15:41:59 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dlen;
	unsigned int		slen;
	unsigned int		i;
	unsigned int		res;

	res = 0;
	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	else
		res = slen + dlen;
	while (src[i] && dlen < size - 1)
	{
		dest[dlen] = src[i];
		dlen++;
		i++;
	}
	dest[dlen] = '\0';
	return (res);
}
