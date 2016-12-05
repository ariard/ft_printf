/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:47:30 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 18:53:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_conv_hexmaj(unsigned long long int i)
{
	char	*s;
	char	*base;
	int		index;
	int		j;

	s = ft_strnew(32);
	base = "0123456789ABCDEF";
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
	return (s);
}
