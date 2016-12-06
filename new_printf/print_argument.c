/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/06 22:53:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_print_invalid(t_flag *flags)
{
	int			n;
	int			len;

	len = 1;
	n = 1;
	if (flags->min_width) 
		n += ft_print_minwidth(flags, len);
	ft_putchar(flags->invalid);
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);
	return (n);
}

int				ft_print_formated_argument(va_list ap, t_print *tab[], t_flag *flags)
{
	int			i;
	int 		len;

	i = 5;
	while (i < 21)
	{
		if (flags->type == tab[i]->c)
			len = tab[i]->f(flags, ap);
		i++;
	}
//	if (flags->invalid)
//		len = ft_print_invalid(flags);
	return (len);
}
