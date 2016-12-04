/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:16:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 18:59:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_string(t_flag *flags, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (flags->max_width)
		ft_putstrn(s, flags->max_width);
	else
		ft_putstr(s);
	return (ft_strlen(s));
}

int			ft_print_char(t_flag *flags, va_list ap)
{
	char	c;

	(void)flags;
	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int			ft_print_pointer(t_flag *flags, va_list ap)
{
	void	*p;
	int		n;

	(void)flags;
	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	n = ft_put_hex((unsigned long long int)p);
	return (n + 2);
}

int			ft_print_pourcentage(t_flag *flags, va_list ap)
{
	(void)flags;
	(void)ap;
	ft_putchar('%');
	return (1);
}
