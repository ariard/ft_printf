/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 23:19:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_print_formated_argument(va_list ap, t_print *tab[], t_flag *flags)
{
	int			i;
	int 		len;

	i = 0;
	len = 0;
//	if (flags->min_width)
	while (i < 5)
	{
		if (flags->precedence == tab[i]->c)
			len += tab[i]->f(flags, ap);
	   	i++;
	}
	i = 5;
	while (i < 20)
	{
		if (flags->type == tab[i]->c)
			len += tab[i]->f(flags, ap);
		i++;
	}
	return (len);
}
