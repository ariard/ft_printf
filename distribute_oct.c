/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_oct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:20:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 16:15:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_oct4(t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->hex)
		len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	if (flags->max_width)
		len += ft_putchar('0');
	return (len);
}

int			ft_print_oct1(t_flag *flags, va_list ap)
{
	unsigned long long int	i;
	char					new[1024];
	int						len;

	i = ft_get_unsignvalue(flags, ap);
	ft_conv_oct(i, new);
	len = 1;
	if (i != 0)
		len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_oct4(flags));
	if (flags->hex && i != 0)
		len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	return (len);
}

int			ft_print_oct2(t_flag *flags, va_list ap)
{
	unsigned long long int 	i;
	char					new[1024];
	int						len;
	int						cp;

	i = ft_get_unsignvalue(flags, ap);
	ft_conv_oct(i, new);
	len = 1;
	if (i != 0)
		len = ft_strlen(new);
	cp = flags->max_width;
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_oct4(flags));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->hex && i != 0 && ((size_t)cp <= ft_strlen(new)))
		len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	return (len);
}

int			ft_distribute_oct(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_oct1(flags, ap);
	else
		n += ft_print_oct2(flags, ap);
	return (n);
}
