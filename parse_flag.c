/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:48:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 14:05:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_parse_pre(const char *format, t_flag *flags, t_print *tab[])
{
	int			len;

	(void)tab;
	len = 0;
	while (*format && (*format == '#' || *format == '0'
			|| *format == '+' || *format == ' ' || *format == '-'))
	{
		if (*format == '#')
			flags->hex = '#';
		if (*format == '-')
			flags->minus = '-';
		if (*format == ' ')
			flags->space = ' ';
		if (*format == '0')
			flags->zero = '0';
		if (*format == '+')
			flags->sign = '+';
		len++;
		format++;
	}
	return (len);
}

int				ft_parse_minwidth(const char *format, t_flag *flags)
{
	int			len;
	char		new[1024];
	char		*tmp;

	len = 0;
	tmp = (char *)format;
	while (*format >= '0' && *format <= '9')
	{
		len++;
		format++;
	}
	if (len)
	{
		ft_bzero(new, 1024);
		ft_strncpy(new, tmp, len);
		flags->min_width = ft_atoi(new);
	}
	return (len);
}

int				ft_parse_maxwidth(const char *format, t_flag *flags)
{
	int			len;
	char		new[1024];
	char		*tmp;

	len = 1;
	if (*format == '.')
		format++;
	tmp = (char *)format;
	while (*format >= '0' && *format <= '9')
	{
		len++;
		format++;
	}
	if (len)
	{
		ft_bzero(new, 1024);
		ft_strncpy(new, tmp, len);
		if (*new == '0')
			return (2);
		flags->max_width = ft_atoi(new);
	}
	if (flags->max_width == 0)
		return (0);
	return (len);
}

int				ft_parse_flag2(const char *format, t_flag *flags)
{
	int			n;

	n = ft_parse_maxwidth(format, flags);
	if (n == 0 && *format == '.')
	{
		n = 1;
		flags->nullwidth = 1;
	}
	if (n == 2 && !flags->max_width)
		flags->nullwidth = 1;
	return (n);
}

int				ft_parse_flag(const char *format, t_flag *flags, t_print *tab[])
{
	int			len;
	int			n;

	len = 0;
	if (*(format + 1) == 0)
		return (0);
	format++;
	n = ft_parse_pre(format, flags, tab);
	format += n;
	len += n;
	n = ft_parse_minwidth(format, flags);
	format += n;
	len += n;
	n = ft_parse_flag2(format, flags);
	format += n;
	len += n;
	n = ft_parse_prom(format, flags, tab);
	format += n;
	len += n;
	n = ft_parse_type(format, flags, tab);
	format += n;
	len += n;
	ft_solve_conflict(flags);
	return (len);
}
