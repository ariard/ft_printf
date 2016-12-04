/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:50:10 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 14:54:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include "stdarg.h"

#define RESET "\x1B[0m"
#define RED	"\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"

typedef struct		s_flag
{
	char			precedence;
	int				min_width;
	int				max_width;
	char			type;
	char			promotion;
}					t_flag;

typedef struct		s_print
{
	char			c;
	int				(*f)(t_flag *, va_list);
}					t_print;

int		ft_printf(const char *format, ...);

int		ft_print_formated_argument(va_list ap, t_print *tab[], t_flag *flags);

int		ft_parse_flag(const char *format, t_flag *flags, t_print *tab[]);

int		ft_parse_prom(const char *format, t_flag *flags, t_print *tab[]);

int		ft_parse_type(const char *format, t_flag *flags, t_print *tab[]);

void	ft_solve_conflict(t_flag *flags);

int		ft_print_string(t_flag *flags, va_list ap);

int		ft_print_char(t_flag *flags, va_list ap);

int		ft_print_pointer(t_flag *flags, va_list ap);

int		ft_print_pourcentage(t_flag *flags, va_list ap);

int		ft_print_int(t_flag *flags, va_list ap);

#endif
