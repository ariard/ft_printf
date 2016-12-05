/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:01:58 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 17:27:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_get_signvalue(t_flag *flags, va_list ap)
{
	if (flags->promotion == 'h' && flags->type != 'O' && flags->type != 'D'
		&& flags->type != 'U')
		return ((short)va_arg(ap, int));
	else if (flags->promotion == 'w' && flags->type != 'O' && flags->type != 'D'
		&& flags->type != 'U') 
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, long long int));
	return (0);
}

unsigned long long int	ft_get_unsignvalue(t_flag *flags, va_list ap)
{
	if (flags->promotion == 'h' && flags->type != 'O' && flags->type != 'D'
		&& flags->type != 'U')
		return ((unsigned short)va_arg(ap, int));
	if (flags->promotion == 'w' && flags->type != 'O' && flags->type != 'D'
		&& flags->type != 'U') 
		return ((unsigned char)va_arg(ap, int));
	else
		return (va_arg(ap, unsigned long long int));
	return (0);
}
