/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:50:10 by ariard            #+#    #+#             */
/*   Updated: 2016/12/09 21:38:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <wchar.h>


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
	char			sign;
	char			space;
	char			zero;
	char			minus;
	char			hex;
	int				min_width;
	int				max_width;
	int				nullwidth;
	char			type;
	char			promotion;
	char			invalid;
}					t_flag;

typedef struct		s_print
{
	char			c;
	int				(*f)(t_flag *, va_list);
}					t_print;

int					ft_printf(const char *format, ...);

int					ft_print_formated_argument(va_list ap, t_print *tab[], t_flag *flags);

int					ft_parse_flag(const char *format, t_flag *flags, t_print *tab[]);

int					ft_parse_prom(const char *format, t_flag *flags, t_print *tab[]);

int					ft_parse_type(const char *format, t_flag *flags, t_print *tab[]);

void				ft_solve_conflict(t_flag *flags, const char *format);

int					ft_print_hex(t_flag *flags);

long long int		ft_get_signvalue(t_flag *flags, va_list ap);

unsigned long long	ft_get_unsignvalue(t_flag *flags, va_list ap);

int					ft_print_minwidth(t_flag *flags, int len);

int					ft_print_minwidth_minus(t_flag *flags, int len);

int					ft_print_maxwidth(t_flag *flags, int len);

int					ft_print_sign(t_flag *flags, long long int i);

int					ft_distribute_int(t_flag *flags, va_list ap);

int					ft_distribute_long(t_flag *flags, va_list ap);

int					ft_distribute_uns(t_flag *flags, va_list ap);

int					ft_distribute_oct(t_flag *flags, va_list ap);

int					ft_distribute_hex(t_flag *flags, va_list ap);

int					ft_distribute_hexmaj(t_flag *flags, va_list ap);

int					ft_distribute_pointer(t_flag *flags, va_list ap);

int					ft_distribute_string(t_flag *flags, va_list ap);

int					ft_distribute_char(t_flag *flags, va_list ap);

int					ft_distribute_pourcent(t_flag *flags, va_list ap);

int					ft_distribute_invalid(t_flag *flags);

int					ft_distribute_wchar(t_flag *flags, va_list ap);

int					ft_distribute_wstring(t_flag *flags, va_list ap);

int					ft_putwchar(wchar_t w);

int					ft_putwstr(wchar_t *w, int cp);

size_t				ft_strwlen(wchar_t *w);

size_t				ft_sizewchar(wchar_t w);

size_t				ft_strwlen_max(wchar_t *w, int cp);

#endif
