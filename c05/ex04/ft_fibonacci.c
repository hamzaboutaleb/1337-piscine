/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:54:42 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/04 10:03:22 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_fib(int index, int next, int prev)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (prev);
	return (ft_recursive_fib(index - 1, next + prev, next));
}

int	ft_fibonacci(int index)
{
	return (ft_recursive_fib(index, 1, 0));
}
