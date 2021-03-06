/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:12:07 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 19:01:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_put_hex(unsigned long long int i)
{
	char	s[32];
	char	*base;
	int		index;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	while (i)
	{
		index = i % 16;
		s[j] = base[index];
		j++;
		i = i / 16;
	}
	s[j] = 0;
	ft_strrev(s);
	ft_putstr(s);
	return (ft_strlen(s));
}
