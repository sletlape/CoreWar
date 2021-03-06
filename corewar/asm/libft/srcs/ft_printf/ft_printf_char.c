/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:23 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:25 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(char out, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar_fd(out, arg->fd);
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
			ft_putchar_fd(out, arg->fd);
		}
	}
	else
		ft_putchar_fd(out, arg->fd);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t	len;

	if (arg->conversion == '%')
		c = '%';
	else
	{
		if (arg->length_mod == l)
			return (ft_printf_wchar(arg, lst));
		c = (char)va_arg(*lst, int);
	}
	len = 1;
	padding(c, arg, len);
	return (len);
}
