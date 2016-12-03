/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 15:12:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_formated_argument(va_list ap, const char *string, size_t jump)
{
	int		d;
	char	c;
	char	*s;
	int		n;

	while (*string && jump)
	{
		if (*string == 's')
		{
			s = va_arg(ap, char *);
			if (s == NULL)
				n = (int)ft_putstr("(null)");
			else
				n = (int)ft_putstr(s);
		}
		if (*string == 'd')
		{
			d = va_arg(ap, int);
		   	ft_putnbr(d);
			n = (int)ft_intlen(d);
		}
		if (*string == 'c')
		{
			c = va_arg(ap, int);
			n = ft_putchar(c);
		}
		string++;
		jump--;
	}
	return (n);
}
