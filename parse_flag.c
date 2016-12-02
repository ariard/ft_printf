/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:48:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/02 19:36:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_parse_precedence(const char *format, t_flag *flags, t_print *tab[])
{
	int			len;
	int			i;

	len = 0;
	i = 0;
	format++;
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
	return (len);
}

int				ft_parse_flag(const char *format, t_print *tab[])
{
	t_flag		*flags;
	int			len;

	flags = ft_memalloc(sizeof(flags));
	len = ft_parse_precedence(format, flags, tab);
	
	printf("precedence :  %c\n", flags->precedence);
	return (len);
}
