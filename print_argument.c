/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 20:42:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_print_invalid(t_flag *flags)
{
	(void)flags;
	return (0);
}

int				ft_print_formated_argument(va_list ap, t_print *tab[], t_flag *flags)
{
	int			i;
	int 		len;

	i = 0;
	len = 0;
	while (i < 5)
	{
		if (flags->precedence == tab[i]->c)
			len += tab[i]->f(flags, ap);
	   	i++;
	}
	i = 5;
	while (i < 21)
	{
		if (flags->type == tab[i]->c)
			len += tab[i]->f(flags, ap);
		i++;
	}
	if (flags->invalid)
		len += ft_print_invalid(flags);
	return (len);
}
