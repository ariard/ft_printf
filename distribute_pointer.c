/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:49:57 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 14:24:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_pointer4(t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	if (flags->max_width)
		len += ft_putchar('0');
	return (len);
}

int			ft_print_pointer1(t_flag *flags, va_list ap)
{
	void				*p;
	char				new[1024];
	int					len;

	p = va_arg(ap, void *); 
	ft_conv_hex((unsigned long long int)p, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len;
	if (p == 0 && flags->nullwidth)
		return (ft_print_pointer4(flags));
	len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len + 2);
	ft_putstr(new);
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_pointer2(t_flag *flags, va_list ap)
{
	void				*i;
	char				new[1024];
	int					len;

	i = va_arg(ap, void *);
	ft_conv_hex((unsigned long long int)i, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len; 
	if (i == 0 && flags->nullwidth)
		return (ft_print_pointer4(flags));
	if (flags->min_width)
		len += ft_print_minwidth(flags, len + 2);
	len += ft_print_hex(flags);
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	return (len);
}

int			ft_print_pointer3(t_flag *flags, va_list ap)
{
	void				*i;
	char				new[1024];
	int					len;

	i = va_arg(ap, void *);
	ft_conv_hex((unsigned long long int)i, new);
	len = ft_strlen(new);
	if (flags->max_width)
		flags->max_width -= len; 
	if (i == 0 && flags->nullwidth)
		return (ft_print_pointer4(flags));
	ft_print_hex(flags);
	if (flags->min_width)
		len += ft_print_minwidth(flags, len + 2);
	len += 2;
	if (flags->max_width)
		len += ft_print_maxwidth(flags, len);
	ft_putstr(new);
	return (len);
}


int			ft_distribute_pointer(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_pointer1(flags, ap);
	else if (flags->zero)
		n += ft_print_pointer3(flags, ap);
	else
		n += ft_print_pointer2(flags, ap);
	return (n);
}
