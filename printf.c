/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 23:54:26 by ariard           ###   ########.fr       */
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
	size_t		jump;

	(void)ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			if ((jump = ft_check_formater(format)))
			{
				ft_print_formated_argument(ap, format, jump);
				while (jump--)
					format++;
			}
		if (*format != '%')
			ft_putchar(*format++);
	}
	return (0);
}
