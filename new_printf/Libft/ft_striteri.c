/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:48:49 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:38:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*p;
	unsigned int	i;

	if (!s || !f)
		return ;
	p = 0;
	p = s;
	i = 0;
	while (*p)
	{
		(*f)(i, p);
		i++;
		p++;
	}
}
