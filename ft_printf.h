/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:50:10 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 23:54:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include "project.h"
# include "stdarg.h"

int		ft_printf(const char *format, ...);

void	ft_print_formated_argument(va_list ap, const char *format, size_t jump);

#endif
