/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/02 15:53:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_check_formater(const char *format)
{
	format++;
	if (*format == 'd')
		return (2);
	if (*format == 's')
		return (2);
	if (*format == 'c')
		return (2);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list 	ap;
	size_t		len;
	int			n;

	n = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			if ((len = ft_check_formater(format)))
			{
				n += ft_print_formated_argument(ap, format, len);
				format += len;
			}
		len = ft_strlenchr(format, '%');
		write(1, format, len);
		n += len;
		format += len;
	}
	va_end(ap);
	return (n);
}
