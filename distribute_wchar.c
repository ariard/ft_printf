/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:01:29 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 15:03:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_printf.h"

int				ft_distribute_wchar(t_flag *flags, va_list ap)
{
	wchar_t		w;
	int			n;

	(void)flags;
	w = va_arg(ap, wchar_t);
	n = ft_putwchar(w);
	return (n);
}
