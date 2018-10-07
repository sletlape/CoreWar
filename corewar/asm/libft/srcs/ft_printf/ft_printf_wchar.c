/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:58 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:03 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(wchar_t out, t_arg *arg, int len)
{
	char	fill;

	fill = ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putwchar_fd(out, arg->fd);
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
			ft_putwchar_fd(out, arg->fd);
		}
	}
	else
		ft_putwchar_fd(out, arg->fd);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_wchar(t_arg *arg, va_list *lst)
{
	wchar_t		c;
	size_t		len;

	c = va_arg(*lst, wchar_t);
	if (c < 0x80)
		len = 1;
	else if (c < 0x800)
		len = 2;
	else if (c < 0x10000)
		len = 3;
	else if (c <= 0x10ffff)
		len = 4;
	else
		len = 0;
	padding(c, arg, len);
	return (len);
}
