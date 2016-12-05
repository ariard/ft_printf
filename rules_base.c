/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 17:04:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_octal(t_flag *flags, va_list ap)
{
	unsigned long long int 	i;
	int					n;

	i = ft_get_unsignvalue(flags, ap);
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	n = ft_put_oct((unsigned long long int)i);
	return (n);
}

int					ft_print_hex(t_flag *flags, va_list ap)
{

	unsigned long long int 	x;
	int						n;

	n = 0;
	x = ft_get_unsignvalue(flags, ap);
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (flags->type == 'x')
		n = ft_put_hex(x);
	else if (flags->type == 'X')
		n = ft_put_hexmaj(x);
	return (n);
}
