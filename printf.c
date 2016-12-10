/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:15:27 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 14:31:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	tab[0] = ft_create_print('s', &ft_distribute_string);
	tab[1] = ft_create_print('S', &ft_distribute_wstring);
	tab[2] = ft_create_print('p', &ft_distribute_pointer);
	tab[3] = ft_create_print('d', &ft_distribute_int);
	tab[4] = ft_create_print('D', &ft_distribute_long);
	tab[5] = ft_create_print('i', &ft_distribute_int);
	tab[6] = ft_create_print('o', &ft_distribute_oct);
	tab[7] = ft_create_print('O', &ft_distribute_oct);
	tab[8] = ft_create_print('u', &ft_distribute_uns);
	tab[9] = ft_create_print('U', &ft_distribute_uns);
	tab[10] = ft_create_print('x', &ft_distribute_hex);
	tab[11] = ft_create_print('X', &ft_distribute_hexmaj);
	tab[12] = ft_create_print('C', &ft_distribute_wchar);
	tab[13] = ft_create_print('c', &ft_distribute_char);
	tab[14] = ft_create_print('%', &ft_distribute_pourcent);
	tab[15] = ft_create_print('y', NULL);
	tab[16] = ft_create_print('w', NULL);
	tab[17] = ft_create_print('l', NULL);
	tab[18] = ft_create_print('h', NULL);
	tab[19] = ft_create_print('z', NULL);
	tab[20] = ft_create_print('j', NULL);
}

int				ft_print_all(const char *format, va_list ap,
		t_flag *flags, t_print *tab[])
{
	int			len;
	int			len2;
	int			n;

	n = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_init_flags();
			len = ft_parse_flag(format, flags, tab);
			if (flags->invalid)
				len++;
			len2 = ft_print_formated_argument(ap, tab, flags);
			n += len2;
			format += len + 1;
			ft_clean_flags(flags);
		}
		len = ft_strlenchr(format, '%');
		write(1, format, len);
		n += len;
		format += len;
	}
	return (n);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	int			i;
	t_print		*tab[22];
	t_flag		*flags;

	ft_bzero(tab, 21);
	ft_gen_tab_print(tab);
	flags = NULL;
	va_start(ap, format);
	n = ft_print_all(format, ap, flags, tab);
	i = 0;
	while (i < 21)
		ft_memdel((void **)&tab[i++]);
	va_end(ap);
	return (n);
}
