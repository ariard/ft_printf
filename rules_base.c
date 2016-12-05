/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 22:46:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_octal(t_flag *flags, va_list ap)
{
	unsigned long long int 	i;
	int						n;
	char					*new;
	int						len;

	i = ft_get_unsignvalue(flags, ap);
	new = ft_conv_oct(i);
	len = 1;
	if (i != 0)
		len = ft_strlen(new);
	n = len;
	if (flags->precedence == '#' && i != 0 && flags->min_width)
		len += 1;
	if (flags->min_width && flags->precedence != '-')
		n += ft_print_minwidth(flags, len);
	if (i == 0)
		ft_putchar('0');
	else
	{
		if (flags->precedence == '#')
			n += ft_putchar('0');
		ft_putstr(new);
	}
	if (flags->min_width && flags->precedence == '-')
		n += ft_print_minwidth(flags, len);
	return (n);
}

int					ft_print_hex(t_flag *flags, va_list ap)
{

	unsigned long long int 	x;
	int						n;
	char					*new;
	int						len;

	n = 0;
	x = ft_get_unsignvalue(flags, ap);
	if (flags->type == 'x')
		new = ft_conv_hex(x);
	else if (flags->type == 'X')
		new = ft_conv_hexmaj(x);
	len = 1;
	if (x != 0)
		len = ft_strlen(new);
	n = len;
	if (flags->precedence == '#' && x != 0 && flags->min_width)
		len += 2;
	if (flags->min_width && flags->precedence != '-')
		n += ft_print_minwidth(flags, len);
	if (x == 0)
		ft_putchar('0');
	else
	{	
		if (flags->precedence == '#' && flags->type == 'x')
			n += ft_putstr("0x");
		else if (flags->precedence == '#' && flags->type == 'X')
			n += ft_putstr("0X");
		ft_putstr(new);
	}
	if (flags->min_width && flags->precedence == '-')
		n += ft_print_minwidth(flags, len);
	return (n);
}
