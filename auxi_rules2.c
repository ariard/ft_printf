/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:22:02 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 00:32:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_hex(t_flag *flags)
{
	int		n;

	n = 0;
	if (flags->hex && (flags->type == 'o' || flags->type == 'O')) 
		n += ft_putchar('0');
	else if (flags->hex && flags->type == 'x') 
		n += ft_putstr("0x");
	else if (flags->type == 'p') 
		n += ft_putstr("0x");
	else if (flags->hex && flags->type == 'X')
		n += ft_putstr("0X");
	return (n);
}

char		*ft_fill(char *tab, char s[], char to_print[], int len2)
{
	int		len;
	int		len3;
	char	new[9];

	len3 = ft_strlen(s) - 1;
	len = ft_strlen(tab) - 1;
	while (len >= 0)
	{
		if (tab[len] == 'x' && len3 >= 0)
			to_print[len2] = s[len3--];
		else
			to_print[len2] = tab[len];
		len--;
		len2--;
	}
	len2++;
	while (to_print[len2])
	{
		if (to_print[len2] == 'x')
			to_print[len2] = '0';
		len2++;
	}
	len2 = ft_strlen(to_print);
	len = 0;
	while (len < len2)
	{
		ft_bzero(new, 9);
		ft_strchrcpy(new, &to_print[len], ' ');
		ft_putchar(ft_atoi_binary(new));
		len += 9;
	}
	return (to_print);
}

int			ft_putwchar(wchar_t w)
{
	char	s[1024];
	char	to_print[18];
	char	*tab;
	int		len2;

	ft_bzero(to_print, 18);
	ft_itoa_binary((int)w, s);
	if ((int)w < 2048)
	{
		tab = "110xxxxx 10xxxxxx";
		len2 = 16;
		ft_fill(tab, s, to_print, len2);
	}
	else if ((int)w < 65536)
	{
		tab = "1110xxxx 10xxxxxx 10xxxxxx";
		len2 = 23;
		ft_fill(tab, s, to_print, len2);
	}
	else if ((int)w < 2097152)
	{
		tab = "11110xxx 10xxxxxx 10xxxxxx";
		len2 = 30;
		ft_fill(tab, s, to_print, len2);
	}
	return (0);
}
