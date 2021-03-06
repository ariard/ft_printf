/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:01:58 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 13:36:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_get_signvalue(t_flag *flags, va_list ap)
{
	if (flags->promotion == 'h' && flags->type != 'O' && flags->type != 'D'
			&& flags->type != 'U')
		return ((short)va_arg(ap, int));
	else if (flags->promotion == 'w' && flags->type != 'O' && flags->type != 'D'
			&& flags->type != 'U')
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, long long int));
	return (0);
}

unsigned long long int	ft_get_unsignvalue(t_flag *flags, va_list ap)
{
	if (flags->promotion == 'h' && flags->type != 'O' && flags->type != 'D'
			&& flags->type != 'U')
		return ((unsigned short)va_arg(ap, int));
	else if (flags->promotion == 'w' && flags->type != 'O' && flags->type != 'D'
			&& flags->type != 'U')
		return ((unsigned char)va_arg(ap, int));
	else if (flags->type == 'U' || flags->type == 'O')
		return (va_arg(ap, unsigned long long int));
	else if ((flags->type == 'x' || flags->type == 'X')
			&& (flags->promotion == 'l' || flags->promotion == 'y'
				|| flags->promotion == 'z' || flags->promotion == 'j'))
		return (va_arg(ap, unsigned long long int));
	else
		return (va_arg(ap, unsigned int));
	return (0);
}

int						ft_print_minwidth(t_flag *flags, int len)
{
	int		n;

	n = 0;
	if (flags->max_width > 0 && flags->type != 's' && flags->type != 'S'
			&& flags->type != 'c' && flags->type != 'C')
		len += flags->max_width;
	if ((flags->sign || flags->space) && flags->type != 'p' && !flags->zero)
		len += 1;
	if (flags->hex && (flags->type == 'x' || flags->type == 'X')
			&& !flags->zero)
		len += 2;
	if (flags->hex && (flags->type == 'o' || flags->type == 'O')
			&& !flags->zero)
		len += 1;
	if ((len = flags->min_width - len) > 0)
	{
		n += len;
		if (!flags->zero)
			while (len--)
				ft_putchar(32);
		else
			while (len--)
				ft_putchar(48);
	}
	return (n);
}

int						ft_print_maxwidth(t_flag *flags, int len)
{
	int		n;

	n = 0;
	if ((len = flags->max_width) > 0)
	{
		n += len;
		if (flags->type != 'c')
			while (len--)
				ft_putchar(48);
		else
		{
			len -= 1;
			n = len;
			while (len--)
				ft_putchar(32);
		}
	}
	return (n);
}

int						ft_print_sign(t_flag *flags, long long int i)
{
	int					n;

	n = 0;
	if (flags->sign && i >= 0)
		n += ft_putchar('+');
	else if ((flags->space == ' ' && i >= 0) || (flags->space == ' '
				&& i < 0 && flags->min_width && flags->type != 'D'))
		n += ft_putchar(' ');
	return (n);
}
