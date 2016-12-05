/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:49:03 by ariard            #+#    #+#             */
/*   Updated: 2016/12/05 18:49:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_conv_oct(unsigned long long int i)
{
	char	*s;
	char	*base;
	int		index;
	int		j;

	s = ft_strnew(32);
	base = "01234567";
	j = 0;
	while (i)
	{
		index = i % 8;
		s[j] = base[index];
		j++;
		i = i / 8;
	}
	s[j] = 0;
	ft_strrev(s);
	return (s);
}
