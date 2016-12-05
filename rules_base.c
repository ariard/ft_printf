/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 18:55:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_octal(t_flag *flags, va_list ap)
{
	unsigned long long int 	i;
	int						n;
	char					*new;
//	int						len;

	i = ft_get_unsignvalue(flags, ap);
	new = ft_conv_oct(i);
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
//	len = ft_unsintlen(i);
//	if (flags->min_width && flags->type != 'O')
//		n += ft_print_minwidth(flags, len);
	n = ft_putstr(new);
	return (n);
}

int					ft_print_hex(t_flag *flags, va_list ap)
{

	unsigned long long int 	x;
	int						n;
	char					*new;
//	int						len;

	n = 0;
	x = ft_get_unsignvalue(flags, ap);
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
//	len = ft_unsintlen(x);
//	if (flags->min_width)
//		n += ft_print_minwidth(flags, len);
	if (flags->type == 'x')
		new = ft_conv_hex(x);
	else if (flags->type == 'X')
		new = ft_conv_hexmaj(x);
	n = ft_putstr(new);
	return (n);
}
