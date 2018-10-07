/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:13:25 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 11:24:07 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_arg
{
	int			flag_alt;
	int			flag_zero;
	int			flag_left;
	int			flag_space;
	int			flag_sign;
	int			field_width;
	int			precision;
	int			prec_set;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			length_mod;
	char		conversion;
	int			size;
	int			fd;
}				t_arg;

int				ft_printf_core(int fd, const char *format, va_list *lst);
int				ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst);
int				ft_printf_handler(t_arg *arg, va_list *lst);

int				ft_printf_char(t_arg *arg, va_list *lst);
int				ft_printf_noconv(t_arg *arg, va_list *lst);
int				ft_printf_signed_decimal(t_arg *arg, va_list *lst);
int				ft_printf_string(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_decimal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_hex(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_octal(t_arg *arg, va_list *lst);
int				ft_printf_wchar(t_arg *arg, va_list *lst);
int				ft_printf_wstring(t_arg *arg, va_list *lst);

void			ft_printf_signedtostr(char *out, intmax_t num, t_arg *arg);
void			unstostr_base(char *out, uintmax_t num, t_arg *arg, char *base);

int				get_int_arg(va_list *lst);
int				idigits(intmax_t n, int base);
int				udigits(uintmax_t n, int base);

void			ft_printf_putnchar(char c, int times, int fd);

#endif
