/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_hexmaj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:30:36 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 19:09:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_hexmaj4(t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	if (flags->max_width)
		len += ft_putchar('0');
	return (len);
}

int			ft_print_hexmaj1(t_flag *flags, va_list ap)
{
	unsigned long long	i;
	char				new[1024];
	int					len;

	i = ft_get_unsignvalue(flags, ap);
	ft_conv_hexmaj(i, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_hexmaj4(flags));
	if (flags->hex && i != 0)
		len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_hexmaj2(t_flag *flags, va_list ap)
{
	unsigned long long	i;
	char				new[1024];
	int					len;

	i = ft_get_unsignvalue(flags, ap);
	ft_conv_hexmaj(i, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_hexmaj4(flags));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->hex && i != 0)
		len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	return (len);
}

int			ft_print_hexmaj3(t_flag *flags, va_list ap)
{
	unsigned long long	i;
	char				new[1024];
	int					len;

	i = ft_get_unsignvalue(flags, ap);
	ft_conv_hexmaj(i, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_hexmaj4(flags));
	if (flags->hex && i != 0)
		len += ft_print_hex(flags);
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	return (len);
}

int			ft_distribute_hexmaj(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_hexmaj1(flags, ap);
	else if (flags->zero)
		n += ft_print_hexmaj3(flags, ap);
	else
		n += ft_print_hexmaj2(flags, ap);
	return (n);
}
