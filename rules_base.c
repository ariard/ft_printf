/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 18:18:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_octal(t_flag *flags, va_list ap)
{
	unsigned long int 	i;
	int					n;

	(void)flags;
	i = va_arg(ap, unsigned long int);
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	n = ft_put_oct((unsigned long int)i);
	return (n);
}
