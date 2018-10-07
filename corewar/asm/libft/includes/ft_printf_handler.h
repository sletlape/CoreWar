/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:17:17 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 10:17:20 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HANDLER_H
# define FT_PRINTF_HANDLER_H
# include <stdarg.h>
# include "ft_printf_internal.h"

typedef int	(*t_func)(t_arg*, va_list*);

typedef struct	s_handler
{
	char	conv;
	t_func	f;
}				t_handler;

t_handler	g_table[] =
{
	{'%', &ft_printf_char},
	{'i', &ft_printf_signed_decimal},
	{'d', &ft_printf_signed_decimal},
	{'D', &ft_printf_signed_decimal},
	{'o', &ft_printf_unsigned_octal},
	{'O', &ft_printf_unsigned_octal},
	{'u', &ft_printf_unsigned_decimal},
	{'U', &ft_printf_unsigned_decimal},
	{'x', &ft_printf_unsigned_hex},
	{'X', &ft_printf_unsigned_hex},
	{'p', &ft_printf_unsigned_hex},
	{'s', &ft_printf_string},
	{'S', &ft_printf_wstring},
	{'c', &ft_printf_char},
	{'C', &ft_printf_wchar},
	{0, 0}
};

#endif
