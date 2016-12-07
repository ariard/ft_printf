/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:22:02 by ariard            #+#    #+#             */
/*   Updated: 2016/12/07 00:27:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_hex(t_flag *flags)
{
	int		n;

	n = 0;
	if (flags->hex && (flags->type == 'o' || flags->type == 'O')) 
		n += ft_putchar('0');
	else if (flags->hex && flags->type == 'x') 
		n += ft_putstr("0x");
	else if (flags->type == 'p') 
		n += ft_putstr("0x");
	else if (flags->hex && flags->type == 'X')
		n += ft_putstr("0X");
	return (n);
}
