/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribute_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:04:25 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 19:10:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_long4(t_flag *flags, long long int i)
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

int			ft_print_long1(t_flag *flags, va_list ap)
{
	long long		i;
	int				len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_long4(flags, i));
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

int			ft_print_long2(t_flag *flags, va_list ap)
{
	long long	i;
	int			len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_long4(flags, i));
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

int			ft_print_long5(t_flag *flags, va_list ap)
{
	long long	i;
	int			len;

	i = ft_get_signvalue(flags, ap);
	len = ft_intlen(i);
	if (flags->max_width && i > 0)
		flags->max_width -= len;
	else
		flags->max_width -= len - 1;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_long4(flags, i));
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

int			ft_distribute_long(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_long1(flags, ap);
	else if (flags->zero)
		n += ft_print_long2(flags, ap);
	else
		n += ft_print_long2(flags, ap);
	return (n);
}
