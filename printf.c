/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 22:28:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_nothing(t_flag *test, va_list test2)
{
	(void)test;
	(void)test2;
	return (0);
}

t_print			*ft_create_print(char c, int (*f)(t_flag *, va_list))
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
	tab[5] = ft_create_print('s', &ft_print_string);
	tab[6] = ft_create_print('S', &ft_nothing);
	tab[7] = ft_create_print('p', &ft_print_pointer);
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
	tab[18] = ft_create_print('c', &ft_print_char);
	tab[19] = ft_create_print('%', &ft_nothing);
	tab[20] = ft_create_print('y', &ft_nothing);
	tab[21] = ft_create_print('w', &ft_nothing);
	tab[22] = ft_create_print('l', &ft_nothing);
	tab[23] = ft_create_print('h', &ft_nothing);
	tab[24] = ft_create_print('z', &ft_nothing);
	tab[25] = ft_create_print('j', &ft_nothing);
}

int				ft_printf(const char *format, ...)
{
	va_list 	ap;
	int			len;
	int			len2;
	int			n;
	t_print		*tab[26];
	t_flag		*flags;

	n = 0;
	ft_gen_tab_print(tab);
	flags = ft_memalloc(sizeof(flags));
	tab[25] = NULL;
	va_start(ap, format);	
	while (*format)
	{
		if (*format == '%')
			{
				if ((len = ft_parse_flag(format, flags, tab)) == 0)
					len = 1;
				else
					len2 = ft_print_formated_argument(ap, tab, flags);
				n += len2;
				format += len + 1;
			}
		len = ft_strlenchr(format, '%');
		write(1, format, len);
		n += len;
		format += len;
	}
	va_end(ap);
	return (n);
}
