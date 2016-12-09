/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_wstring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:28:33 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 15:26:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_wstring4(t_flag *flags)
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

int			ft_print_wstring1(t_flag *flags, va_list ap)
{
	wchar_t				*w;
	int					len;

	w = va_arg(ap, wchar_t *);
	if (w != NULL)
		len = (int)ft_strwlen(w);
	if (w != NULL && flags->max_width && flags->max_width < (int)ft_strwlen(w))
		len = flags->max_width;
	else if (flags->nullwidth)
		len = 0;
	if (w == NULL && (flags->nullwidth || flags->max_width))
		return (ft_print_wstring4(flags));
	if (w != NULL && flags->max_width && flags->max_width < (int)ft_strwlen(w)) 
		ft_putwstr(w, flags->max_width);
	else if (w != NULL && !flags->nullwidth)
		ft_putwstr(w, -1);
	else if (w == NULL && !flags->nullwidth)
		len += ft_putstr("(null)");
	if (flags->min_width && w != NULL)
		len += ft_print_minwidth_minus(flags, len);
	return (len);
}

int			ft_print_wstring2(t_flag *flags, va_list ap)
{
	wchar_t				*w;
	int					len;

	w = va_arg(ap, wchar_t *);
	if (w != NULL)
		len = (int)ft_strwlen(w);
	if (w != NULL && flags->max_width && flags->max_width < (int)ft_strwlen(w))
		len = (int)ft_strwlen_max(w, flags->max_width);
	else if (flags->nullwidth)
		len = 0;
	if (w == NULL && (flags->nullwidth || flags->max_width))
		return (ft_print_wstring4(flags));
	if (flags->min_width && w != NULL)
		len += ft_print_minwidth(flags, len);
	if (w != NULL && flags->max_width && flags->max_width < (int)ft_strwlen(w))
		ft_putwstr(w, flags->max_width); 
	else if (w != NULL && !flags->nullwidth)
		ft_putwstr(w, -1);
	else if (w == NULL && !flags->nullwidth)
		len += ft_putstr("(null)");
	return (len);
}

int			ft_distribute_wstring(t_flag *flags, va_list ap)
{
	int		n;

	n = 0;
	if (flags->minus)
		n += ft_print_wstring1(flags, ap);
	else
		n += ft_print_wstring2(flags, ap);
	return (n);
}
