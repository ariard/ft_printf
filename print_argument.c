/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 23:54:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_formated_argument(va_list ap, const char *string, size_t jump)
{
	int		d;
	char	c;
	char	*s;

	while (*string && jump)
	{
		if (*string == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
		}
		if (*string == 'd')
		{
			d = va_arg(ap, int);
		   	ft_putnbr(d);
		}
		if (*string == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar(c);
		}
		string++;
		jump--;
	}	
}
