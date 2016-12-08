/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_rules3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:54:52 by ariard            #+#    #+#             */
/*   Updated: 2016/12/08 18:51:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_sizewchar(wchar_t w)
{
	if ((int)w < 128)
		return (1);
	else if ((int)w < 2048)
		return (2);
	else if ((int)w < 65536)
		return (3);
	else
		return (4);
}

size_t		ft_strwlen(wchar_t *w)
{
	int		len;

	len = 0;
	while (*w)
		len += ft_sizewchar(*w++);
	return (len);
}

size_t		ft_strwlen_max(wchar_t *w, int cp)
{
	int		len;

	len = 0;
	while ((cp -= (int)ft_sizewchar(*w)) >= 0)
	{
		len += (int)ft_sizewchar(*w);
		w++;
	}
	return (len);
}
