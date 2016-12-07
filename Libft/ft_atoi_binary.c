/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:19:57 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 00:23:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_recursive_power(int nb, int power)
{
	if (power > 1)
		nb = (nb * ft_recursive_power(nb, power - 1));
	if (power == 0)
		nb = 1;
	if (power < 0)
		nb = 0;
	return (nb);
}

int				ft_atoi_binary(char *s)
{
	unsigned long long 	nb;
	int					rank;

	nb = 0;
	rank = ft_strlen(s) - 1;
	while(*s >= '0' && *s <= '9')
	{
		nb += (*s - '0') * ft_recursive_power(2, rank);
		s++;
		rank--;
	}
	return (nb);
}
