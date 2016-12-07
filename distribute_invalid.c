/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_invalid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:19:26 by ariard            #+#    #+#             */
/*   Updated: 2016/12/07 16:26:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_invalid1(t_flag *flags)
{
	int					len;

	len = 1;
	ft_putchar(flags->invalid);
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	return (len);
}

int			ft_print_invalid2(t_flag *flags)
{
	int					len;

	len = 1;
	if (flags->min_width)
		len += ft_print_minwidth(flags, len);
	ft_putchar(flags->invalid);
	return (len);
}

int			ft_distribute_invalid(t_flag *flags)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_invalid1(flags);
	else
		n += ft_print_invalid2(flags);
	return (n);
}
