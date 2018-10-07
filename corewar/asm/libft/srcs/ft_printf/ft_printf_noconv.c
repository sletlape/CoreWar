/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_noconv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:34 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:35 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(t_arg *arg)
{
	char	fill;
	int		len;

	fill = arg->flag_zero ? '0' : ' ';
	len = 1;
	if (arg->prec_set && arg->precision > 1)
		len = ft_min(1, arg->precision);
	if (arg->field_width > 1)
	{
		if (arg->flag_left)
		{
			ft_putchar_fd(arg->conversion, arg->fd);
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
			ft_putchar_fd(arg->conversion, arg->fd);
		}
	}
	else
		ft_putchar_fd(arg->conversion, arg->fd);
	arg->size = ft_max(1, arg->field_width);
}

int				ft_printf_noconv(t_arg *arg, va_list *lst)
{
	(void)lst;
	padding(arg);
	return (1);
}
