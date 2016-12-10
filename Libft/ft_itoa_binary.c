/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:41:39 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 14:34:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa_binary(int n, char new[])
{
	char				s[1024];
	int					index;
	unsigned long long	nb;

	if (n < 0)
		return (0);
	nb = n;
	index = 0;
	ft_bzero(s, 1024);
	ft_bzero(new, 1024);
	if (nb == 0)
		s[index] = '0';
	while (nb > 0)
	{
		s[index++] = nb % 2 + '0';
		nb = nb / 2;
	}
	s[index] = 0;
	ft_strrev(s);
	ft_strcpy(new, s);
	return (new);
}
