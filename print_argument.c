/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:02:41 by ariard            #+#    #+#             */
/*   Updated: 2016/12/10 14:29:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			*ft_init_flags(void)
{
	t_flag		*flags;

	flags = ft_memalloc(sizeof(t_flag));
	flags->sign = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->hex = 0;
	flags->min_width = 0;
	flags->max_width = 0;
	flags->nullwidth = 0;
	flags->type = 0;
	flags->promotion = 0;
	flags->invalid = 0;
	return (flags);
}

void			ft_clean_flags(t_flag *flags)
{
	flags->sign = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->hex = 0;
	flags->min_width = 0;
	flags->max_width = 0;
	flags->nullwidth = 0;
	flags->type = 0;
	flags->promotion = 0;
	flags->invalid = 0;
	free(flags);
	flags = NULL;
}

int				ft_print_formated_argument(va_list ap, t_print *tab[],
		t_flag *flags)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (i < 15)
	{
		if (flags->type == tab[i]->c)
			len = tab[i]->f(flags, ap);
		i++;
	}
	if (flags->invalid)
		len = ft_distribute_invalid(flags);
	return (len);
}
