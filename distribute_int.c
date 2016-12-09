/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribute_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:29:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 20:02:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_int4(t_flag *flags, long long int i)
{
	int		len;

	len = 0;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->sign || flags->space)
		len += ft_print_sign(flags, i);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	return (len);
}

int			ft_print_int1(t_flag *flags, va_list ap)
{
	int		i;
	int		len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_int4(flags, i));
	if (flags->sign || flags->space)
		len += ft_print_sign(flags, i);
	if (i < 0)
		ft_putchar('-');
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putnbr(i);
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_int2(t_flag *flags, va_list ap)
{
	int		i;
	int		len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_int4(flags, i));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->sign || flags->space)
		len += ft_print_sign(flags, i);
	if (i < 0)
		ft_putchar('-');
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putnbr(i);
	return (len);
}

int			ft_print_int5(t_flag *flags, va_list ap)
{
	int		i;
	int		len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_int4(flags, i));
	if (flags->sign || flags->space)
		len += ft_print_sign(flags, i);
	if (i < 0)
		ft_putchar('-');
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putnbr(i);
	return (len);
}

int			ft_distribute_int(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_int1(flags, ap);
	else if (flags->zero)
		n += ft_print_int5(flags, ap);
	else
		n += ft_print_int2(flags, ap);
	return (n);
}
