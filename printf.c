/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/01 20:29:53 by ariard           ###   ########.fr       */
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

/*int				ft_check_couleur(const char *format)
{
	char		*new;
	size_t		len;

	len = ft_strlenchr(format, 'm');
	new = ft_strnew(len);
	ft_strchrcpy(new, format, 'm');
	if (ft_strcmp(new, RESET) == 0)
		ft_putstr(RESET);
	else if (ft_strcmp(new, RED) == 0)
		ft_putstr(RED);
	else if (ft_strcmp(new, GRN) == 0)
		ft_putstr(GRN);
	else if (ft_strcmp(new, YEL) == 0)
		ft_putstr(YEL);
	else if (ft_strcmp(new, BLU) == 0)
		ft_putstr(BLU);
	else if (ft_strcmp(new, CYN) == 0)
		ft_putstr(CYN);
	else if (ft_strcmp(new, WHT) == 0)
		ft_putstr(WHT);
	ft_strdel(&new);
	return (len);
}*/

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
		format += len;
	}
	va_end(ap);
	return (n);
}
