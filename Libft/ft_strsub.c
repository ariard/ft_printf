/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:52:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:41:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*tmp;

	if (!s)
		return (NULL);
	new = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!(new))
		return (NULL);
	tmp = new;
	while (len--)
	{
		*new = s[start];
		new++;
		start++;
	}
	*new = '\0';
	return (tmp);
}
