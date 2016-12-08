/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:27:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 16:27:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char4(t_flag *flags)
{
	int		len;

	len = 1;
	if (flags->min_width && !flags->minus)
		len += ft_print_minwidth(flags, len);
	if (flags->min_width && flags->minus)
		len += ft_print_maxwidth(flags, len);
	if (flags->min_width)
		ft_putchar(0);
	return (len);
}

int			ft_print_char1(t_flag *flags, va_list ap)
{
	char				c;
	int					len;

	c = va_arg(ap, int);
	len = 1;
	if (c == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_char4(flags));
	ft_putchar(c);
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	return (len);
}

int			ft_print_char2(t_flag *flags, va_list ap)
{
	char				c;
	int					len;

	c = va_arg(ap, int);
	len = 1;
	if (c == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_char4(flags));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	ft_putchar(c);
	return (len);
}

int			ft_distribute_char(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_char1(flags, ap);
	else
		n += ft_print_char2(flags, ap);
	return (n);
}
