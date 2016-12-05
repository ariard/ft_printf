/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:16:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 18:58:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_string(t_flag *flags, va_list ap)
{
	char	*s;
	int		n;
	int		len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(s);
	n = len;
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);	
	ft_putstr(s);
	return (n);
}

int			ft_print_char(t_flag *flags, va_list ap)
{
	char	c;
	int		n;
	int		len;

	c = va_arg(ap, int);
	len = 1;
	n = len;
	if (flags->min_width)
		n += ft_print_minwidth(flags, len);
	ft_putchar(c);
	return (n);
}

int			ft_print_pointer(t_flag *flags, va_list ap)
{
	void	*p;
	int		n;
	int		len;
	char	*new;

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	new = ft_conv_hex((unsigned long long int)p);
	n = ft_putstr(new);
	return (n + 2);
}

int			ft_print_pourcentage(t_flag *flags, va_list ap)
{
	(void)flags;
	(void)ap;
	ft_putchar('%');
	return (1);
}
