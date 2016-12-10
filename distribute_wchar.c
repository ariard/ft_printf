/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:55:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 13:31:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_wchar4(t_flag *flags)
{
	int		len;

	len = 1;
	if (flags->min_width && !flags->minus)
		len += ft_print_minwidth(flags, len);
	if (flags->min_width && flags->minus)
		len += ft_print_maxwidth(flags, len);
	ft_putchar(0);
	return (len);
}

int			ft_print_wchar1(t_flag *flags, va_list ap)
{
	wchar_t				w;
	int					len;

	w = va_arg(ap, wchar_t);
	if (w > 127)
		len = ft_sizewchar(w);
	else
		len = 1;
	if (w == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_wchar4(flags));
	if (w < 128)
		ft_putchar((char)w);
	else
		ft_putwchar(w);
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_wchar2(t_flag *flags, va_list ap)
{
	wchar_t				w;
	int					len;

	w = va_arg(ap, wchar_t);
	if (w > 127)
		len = ft_sizewchar(w);
	else
		len = 1;
	if (w == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_wchar4(flags));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (w < 128)
		ft_putchar((char)w);
	else
		ft_putwchar(w);
	return (len);
}

int			ft_distribute_wchar(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_wchar1(flags, ap);
	else
		n += ft_print_wchar2(flags, ap);
	return (n);
}
