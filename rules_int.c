/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:48:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 18:21:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_int(t_flag *flags, va_list ap)
{
	int		i;
	int		n;
	int		len;

	i = ft_get_signvalue(flags, ap);
	len = (int)ft_intlen(i);
	n = len;
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);
	ft_putnbr(i);
	return (n);
}

int			ft_print_unsigned(t_flag *flags, va_list ap)
{
	unsigned int long long u;
	int	n;
	int len;

	u = ft_get_unsignvalue(flags, ap);
	len = ft_unsintlen(u);
	n = len;
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);
	ft_putunsnbr(u);
	return (n);
}

int			ft_print_long(t_flag *flags, va_list ap)
{
	long long i;
	int		n;
	int		len;

	i =  ft_get_signvalue(flags, ap);
	len = (int)ft_intlen(i);
	n = len;
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);
	ft_putnbr(i);
	return (n);
}
