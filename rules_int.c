/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:48:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 16:30:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_int(t_flag *flags, va_list ap)
{
	int		i;
	int		n;
	int		len;

	i = va_arg(ap, int);
	if (i == 0 && flags->min_width == 0)
		return (0);
	len = (int)ft_intlen(i);
	n = len;
	if (flags->min_width)
		if ((len = flags->min_width - len) > 0)
		{
			n += len;
			while (len--)
				ft_putchar(32);
		}
	ft_putnbr(i);
	return (n);
}		
