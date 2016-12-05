/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:48:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 12:56:30 by ariard           ###   ########.fr       */
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

int			ft_print_unsigned(t_flag *flags, va_list ap)
{
	unsigned int long long u;
	int	n;

	(void)flags;
	u = va_arg(ap, unsigned long long int);
	n = ft_unsintlen(u);
	ft_putunsnbr(u);
	return (n);
}

int			ft_print_long(t_flag *flags, va_list ap)
{
	long long i;
	int		n;
	int		len;

	i = va_arg(ap, long long);
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
