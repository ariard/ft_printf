/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:05:01 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 14:18:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_string4(t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->min_width && !flags->minus)
		len += ft_print_minwidth(flags, len);
	if (flags->max_width && !flags->min_width)
		ft_putstrn("(null)", flags->max_width);
	else if (!flags->min_width)
		ft_putstr("(null)");
	if (flags->min_width && flags->minus)
		len += ft_print_minwidth(flags, len);
	return (len);
}

int			ft_print_string1(t_flag *flags, va_list ap)
{
	char				*s;
	int					len;

	s = va_arg(ap, char *);
	if (s != NULL)
		len = ft_strlen(s);
	if (s != NULL && flags->max_width && flags->max_width < (int)ft_strlen(s))
		len = flags->max_width;
	else if (flags->nullwidth)
		len = 0;
	if (s == NULL && (flags->nullwidth || flags->max_width))
		return (ft_print_string4(flags));
	if (s != NULL && flags->max_width && flags->max_width < (int)ft_strlen(s)) 
		ft_putstrn(s, flags->max_width);
	else if (flags->nullwidth)
		ft_putstrn(s, 0);
	else if (s != NULL)
		ft_putstr(s);
	else if (s == NULL)
		len += ft_putstr("(null)");
	if (flags->min_width && s != NULL)
		len += ft_print_minwidth(flags, len);
	return (len);
}

int			ft_print_string2(t_flag *flags, va_list ap)
{
	char				*s;
	int					len;

	s = va_arg(ap, char *);
	if (s != NULL)
		len = ft_strlen(s);
	if (s != NULL && flags->max_width && flags->max_width < (int)ft_strlen(s))
		len = flags->max_width;
	else if (flags->nullwidth)
		len = 0;
	if (s == NULL && (flags->nullwidth || flags->max_width))
		return (ft_print_string4(flags));
	if (flags->min_width && s != NULL)
		len += ft_print_minwidth(flags, len);
	if (s != NULL && flags->max_width && flags->max_width < (int)ft_strlen(s))
		ft_putstrn(s, flags->max_width);
	else if (flags->nullwidth)
		ft_putstrn(s, 0);
	else if (s != NULL)
		ft_putstr(s);
	else if (s == NULL)
		len += ft_putstr("(null)");
	return (len);
}

int			ft_distribute_string(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_string1(flags, ap);
	else
		n += ft_print_string2(flags, ap);
	return (n);
}
