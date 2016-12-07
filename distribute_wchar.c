/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:01:29 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 00:51:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_printf.h"

int				ft_distribute_wchar(t_flag *flags, va_list ap)
{
	wchar_t		w;

	(void)flags;
	w = va_arg(ap, wchar_t);
	ft_putwchar(w);
	return (1);
}
