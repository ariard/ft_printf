/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribute_uns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:04:36 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 13:09:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_uns4(t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	return (len);
}

int			ft_print_uns1(t_flag *flags, va_list ap)
{
	unsigned long long 		i;
	int						len;

	i = ft_get_unsignvalue(flags, ap);
	len = ft_unsintlen(i);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_uns4(flags));
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putunsnbr(i);
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_uns3(t_flag *flags, unsigned long long int i)
{
	int		len;

	len = ft_intlen(i);
	if (flags->max_width)
		flags->max_width -= len;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putunsnbr(i);
	if (i == 0)
		len += 1;
	return (len);
}

int			ft_print_uns2(t_flag *flags, va_list ap)
{
	unsigned long long	i;
	int					len;

	i = ft_get_unsignvalue(flags, ap);
	len = ft_unsintlen(i);
	if (flags->max_width)
		flags->max_width -= len;
	if (i == 0 && (flags->nullwidth || flags->max_width))
		return (ft_print_uns4(flags));
	if (i == 0 && flags->zero && !flags->nullwidth)
		return (ft_print_uns3(flags, i));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putunsnbr(i);
	return (len);
}

int			ft_distribute_uns(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_uns1(flags, ap);
	else
		n += ft_print_uns2(flags, ap);
	return (n);
}
