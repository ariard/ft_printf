/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:16:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 23:07:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_string(t_flag *flags, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
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
	void	*s;

	(void)flags;
	s = va_arg(ap, char *);
	write(1, s, ft_strlen(s));
	return (0);
}

int			ft_print_pourcentage(t_flag *flags, va_list ap)
{
	(void)flags;
	(void)ap;
	ft_putchar('%');
	return (1);
}
