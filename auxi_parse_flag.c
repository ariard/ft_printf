/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_parse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:44:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/07 16:29:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_parse_prom(const char *format, t_flag *flags, t_print *tab[])
{
	int			i;

	flags->promotion = 0;
	i = 20;
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
	while (i < 26)
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

	i = 5;
	while (i < 20)
	{
		if (tab[i]->c == *format)
			flags->type = *format;
		i++;
	}
	if (flags->type == 0)
	{
		flags->invalid = *format;
		return (0);
	}
	return (1);
}

void				ft_solve_conflict(t_flag *flags, const char *format)
{
	(void)format;
	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->space && flags->sign)
		flags->space = 0;
	if (flags->hex && (flags->sign || flags->space) && flags->type == 'x')
	{
		flags->space = 0;
		flags->sign = 0;
	}
	if (flags->hex && (flags->sign || flags->space) && flags->type == 'd')
		flags->hex = 0;
	if (flags->zero && flags->max_width)
		flags->zero = 0;
	if ((flags->promotion == 'l' || flags->promotion == 'y') && (
		flags->type == 'd' || flags->type == 'i' ))
		flags->type = 'D';
	if ((flags->promotion == 'j' || flags->promotion == 'z') 
		&& (flags->type == 'd' || flags->type == 'i'))
		flags->type = 'D';
}
