/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/02 20:10:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			ft_nothing(t_flag *test, va_list test2)
{
	(void)test;
	(void)test2;
}

t_print			*ft_create_print(char c, void (*f)(t_flag *, va_list))
{
	t_print		*rules;

//	rules = (t_print *)malloc(sizeof(t_print));
	rules = ft_memalloc(sizeof(rules));
	if (rules)
	{
		rules->c = c;
		rules->f = (*f);
	}
	return (rules);
}

void			ft_gen_tab_print(t_print *tab[])
{
	tab[0] = ft_create_print('#', &ft_nothing);
	tab[1] = ft_create_print(' ', &ft_nothing);
	tab[2] = ft_create_print('+', &ft_nothing);
	tab[3] = ft_create_print('-', &ft_nothing);
	tab[4] = ft_create_print('0', &ft_nothing);
	tab[5] = NULL;
}

int				ft_printf(const char *format, ...)
{
	va_list 	ap;
	size_t		len;
	int			n;
	t_print		*tab[7];

	n = 0;
	ft_gen_tab_print(tab);
	va_start(ap, format);	
	while (*format)
	{
		if (*format == '%')
			{
				if ((len = ft_parse_flag(format, tab)) == 0)
					len = 1;
//				ft_print_formated_argument(ap, format, len);
				n += len;
				format += len;
			}
		len = ft_strlenchr(format, '%');
//		write(1, format, len);
		n += len;
		format += len;
	}
	va_end(ap);
	return (n);
}
