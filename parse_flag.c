/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:48:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/02 20:47:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_parse_precedence(const char *format, t_flag *flags, t_print *tab[])
{
	int			len;

	len = 0;
	while (*format && (*format == '#' || *format == '0' ||		*format == '+' || *format == ' ' || *format == '-'))
	{
		len++;
		format++;
	}
	format--;
	while (*tab)
	{
		if ((*tab)->c == *format)
			flags->precedence = *format;	
		tab++;
	}
	if (flags->precedence == 0)
		len = 0;
	return (len);
}

int				ft_parse_minwidth(const char *format, t_flag *flags)
{
	int 		len;
	char		*new;
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
		new = ft_strnew(len);
		ft_strncpy(new, tmp, len);
		flags->min_width = ft_atoi(new);
		ft_strdel(&new);
	}
	return (len);
}

int				ft_parse_maxwidth(const char *format, t_flag *flags)
{
	int 		len;
	char		*new;
	char		*tmp;

	len = 0;
	format++;
	tmp = (char *)format;
	while (*format >= '0' && *format <= '9')
	{
		len++;
		format++;
	}
	if (len)
	{
		new = ft_strnew(len);
		ft_strncpy(new, tmp, len);
		flags->max_width = ft_atoi(new);
		ft_strdel(&new);
	}
	return (len);
}

int				ft_parse_flag(const char *format, t_print *tab[])
{
	t_flag		*flags;
	int			len;

	format++;
	flags = ft_memalloc(sizeof(flags));
	len = ft_parse_precedence(format, flags, tab);
	format += len;
	len += ft_parse_minwidth(format, flags);
	format += len;
	len += ft_parse_maxwidth(format, flags);

	if (flags->min_width)
		printf("min : %d\n", flags->min_width);
	if (flags->max_width)
		printf("max : %d\n", flags->max_width);

	return (len);
}
