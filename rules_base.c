/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 19:16:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_octal(t_flag *flags, va_list ap)
{
	unsigned long long int 	i;
	int					n;

	(void)flags;
	i = va_arg(ap, unsigned long long int);
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

	(void)flags;
	n = 0;
	x = va_arg(ap, unsigned long long int);
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
