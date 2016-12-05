/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_parse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:44:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 17:49:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_parse_prom(const char *format, t_flag *flags, t_print *tab[])
{
	int			i;

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
		return (0);
	return (1);
}

void			ft_solve_conflict(t_flag *flags)
{
	if (flags->precedence == '#' && (flags->type != 'x' || flags->type != 'X' || 
		flags->type != 'o'))
			flags->precedence = 0;
	if (flags->precedence && (flags->type == 'c' || flags->type == 'C' || 
		flags->type == 's' || flags->type == 'S'))
			flags->precedence = 0;
	if ((flags->min_width || flags->max_width) && (flags->type == 'c' || 
		flags->type == 'C' || flags->type == 's' || flags->type == 'S'))	
		flags->min_width = 0;
	if ((flags->promotion == 'l' || flags->promotion == 'y') && (
		flags->type == 'd' || flags->type == 'i' ))
		flags->type = 'D';
	if ((flags->promotion == 'j' || flags->promotion == 'z') 
		&& (flags->type == 'd' || flags->type == 'i'))
		flags->type = 'D';
}
