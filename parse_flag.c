/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:48:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 16:12:22 by ariard           ###   ########.fr       */
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

int				ft_parse_type(const char *format, t_flag *flags, t_print *tab[])
{
	while (*tab)
	{
		if ((*tab)->c == *format)
			flags->type = *format;
		tab++;
	}
	if (flags->type == 0)
		return (0);
	return (1);
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
	format += len;
	len += ft_parse_prom(format, flags, tab);
	format += len;
	len += ft_parse_type(format, flags, tab);
	
//	ft_check_diff_for_validity
//	ft_solve_conflit_behaviori
	if (flags->type)
		printf("type : %c\n", flags->type);
	return (len);
}
