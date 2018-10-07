/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:43 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:45 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(const char *out, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			write(arg->fd, out, len);
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
			write(arg->fd, out, len);
		}
	}
	else
		write(arg->fd, out, len);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_string(t_arg *arg, va_list *lst)
{
	const char	*str;
	size_t		len;

	if (arg->length_mod == l)
		return (ft_printf_wstring(arg, lst));
	str = va_arg(*lst, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	padding(str, arg, len);
	return (len);
}
