/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:33:15 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 23:07:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t				ft_intlen(int d)
{
	int				len;
	long long		nb;

	len = 0;
	nb = d;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	if (nb == 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}
