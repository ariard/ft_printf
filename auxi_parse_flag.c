/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_parse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:44:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/06 01:52:00 by ariard           ###   ########.fr       */
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
	{
		flags->invalid = *format;
		return (1);
	}
	return (1);
}

void				ft_solve_conflict(t_flag *flags, const char *format)
{
	char			c;
	const char		*new;
	const char		*new2;

	new = format;
	new2 = format;
	if (flags->precedence == '0')
		while (*format && *format != '%') 
		{
			if (*format == ' ')
				flags->precedence = ' ' ;
			format--;
		}
	if (flags->precedence == ' ' || flags->precedence == '0')
		while (*new2 && *new2 != '%') 
		{
			if (*new2 == '+')
				flags->precedence = '+' ;
			new2--;
		}
	while (*new != '%')
		new--;
	new2 = new;
	if (flags->precedence == '#' || flags->precedence == '+' 
		|| flags->precedence == ' ') 
		while (*new && (*new == '#' || *new == '0' || *new == ' ' || *new == '+'
			|| *new == '%'))
		{	
			if (*new == '0')
				flags->zero = '0';
			new++;
		}
	if (flags->precedence == '+' || flags->precedence == ' ')
		while (*new2 && *new2 != flags->precedence)
		{
			if (*new2 == '#')
				flags->precedence = '#';
			new2++;
		}
	if ((flags->promotion == 'l' || flags->promotion == 'y') && (
		flags->type == 'd' || flags->type == 'i' ))
		flags->type = 'D';
	if ((flags->promotion == 'j' || flags->promotion == 'z') 
		&& (flags->type == 'd' || flags->type == 'i'))
		flags->type = 'D';
}
