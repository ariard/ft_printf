/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:27:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 14:09:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_pourcent1(t_flag *flags, va_list ap)
{
	int					len;

	(void)ap;
	len = 1;
	ft_putchar('%');
	if (flags->min_width)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_pourcent2(t_flag *flags, va_list ap)
{
	int					len;

	(void)ap;
	len = 1;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	ft_putchar('%');
	return (len);
}

int			ft_distribute_pourcent(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_pourcent1(flags, ap);
	else
		n += ft_print_pourcent2(flags, ap);
	return (n);
}
