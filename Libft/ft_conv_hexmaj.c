/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:47:30 by ariard            #+#    #+#             */
/*   Updated: 2016/12/07 21:48:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_conv_hexmaj(unsigned long long int i, char new[])
{
	char	s[1024];
	char	*base;
	int		index;
	int		j;

	ft_bzero(s, 1024);
	ft_bzero(new, 1024);
	base = "0123456789ABCDEF";
	j = 0;
	if (i == 0)
		s[j++] = '0';
	while (i)
	{
		index = i % 16;
		s[j] = base[index];
		j++;
		i = i / 16;
	}
	s[j] = 0;
	ft_strrev(s);
	ft_strcpy(new, s);
	return (new);
}
