/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_parse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:44:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 17:21:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parse_prom(const char *format, t_flag *flags, t_print *tab[])
{
	int			i;

	i = 21;
	if (*format == 'l' && *(format + 1) == 'l')
	{
		flags->promotion = 'y';
		return (2);
	}
	if (*format == 'h' && *(format + 1) == 'h')
	{
		flags->promotion = 'w';
		return (2);
	}
	while (i < 25)
	{
		if (tab[i]->c == *format)
			flags->promotion = *format;
		i++;
	}
	if (flags->promotion == 0)
		return (0);
	return (1);
}

int				ft_parse_type(const char *format, t_flag *flags, t_print *tab[])
{
	int			i;

	i = 0;
	while (i < 19)
	{
		if (tab[i]->c == *format)
			flags->type = *format;
		i++;
	}
	if (flags->type == 0)
		return (0);
	return (1);
}
