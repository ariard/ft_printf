/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 15:11:47 by ariard           ###   ########.fr       */
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
	tab[5] = ft_create_print('s', &ft_nothing);
	tab[6] = ft_create_print('S', &ft_nothing);
	tab[7] = ft_create_print('p', &ft_nothing);
	tab[8] = ft_create_print('d', &ft_nothing);
	tab[9] = ft_create_print('D', &ft_nothing);
	tab[10] = ft_create_print('i', &ft_nothing);
	tab[11] = ft_create_print('o', &ft_nothing);
	tab[12] = ft_create_print('O', &ft_nothing);
	tab[13] = ft_create_print('u', &ft_nothing);
	tab[14] = ft_create_print('U', &ft_nothing);
	tab[15] = ft_create_print('x', &ft_nothing);
	tab[16] = ft_create_print('X', &ft_nothing);
	tab[17] = ft_create_print('C', &ft_nothing);
	tab[18] = ft_create_print('%', &ft_nothing);
	tab[19] = ft_create_print('h', &ft_nothing);
	tab[20] = ft_create_print('w', &ft_nothing);
	tab[21] = ft_create_print('l', &ft_nothing);
	tab[22] = ft_create_print('y', &ft_nothing);
	tab[23] = ft_create_print('z', &ft_nothing);
	tab[24] = ft_create_print('j', &ft_nothing);
}

int				ft_printf(const char *format, ...)
{
	va_list 	ap;
	size_t		len;
	int			n;
	t_print		*tab[26];

	n = 0;
	ft_gen_tab_print(tab);
	tab[25] = NULL;
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
		write(1, format, len);
		n += len;
		format += len;
	}
	va_end(ap);
	return (n);
}
