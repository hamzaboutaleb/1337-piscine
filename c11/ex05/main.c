/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:13:16 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/13 19:43:20 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_do_op(int n1, int n2, char *op)
{
	if (ft_strcmp(op, "+") == 0)
		ft_add(n1, n2);
	else if (ft_strcmp(op, "-") == 0)
		ft_sub(n1, n2);
	else if (ft_strcmp(op, "/") == 0)
		ft_div(n1, n2);
	else if (ft_strcmp(op, "*") == 0)
		ft_mul(n1, n2);
	else if (ft_strcmp(op, "%") == 0)
		ft_mod(n1, n2);
	else
		ft_putstr("0");
}

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	char	*op;

	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	op = argv[2];
	n2 = ft_atoi(argv[3]);
	ft_do_op(n1, n2, op);
	ft_putchar('\n');
}
