/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signedtostr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:41 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:42 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static int	getlen(int len, intmax_t num, t_arg *arg)
{
	len = ft_max(len, arg->precision);
	if (num < 0 || arg->flag_space || arg->flag_sign)
		len++;
	return (len);
}

static int	putmodifiers(char *str, intmax_t n, t_arg *arg)
{
	if (n < 0)
		*str = '-';
	else
	{
		if (arg->flag_sign)
			*str = '+';
		else if (arg->flag_space)
			*str = ' ';
		else
			return (0);
	}
	return (1);
}

void		ft_printf_signedtostr(char *out, intmax_t n, t_arg *arg)
{
	int		index;
	int		size;
	int		len;

	len = idigits(n, 10);
	size = getlen(len, n, arg);
	index = 0;
	index += putmodifiers(out + index, n, arg);
	while (index < size - len)
		out[index++] = '0';
	if (n == 0 && !(arg->prec_set && arg->precision == 0))
		out[index] = '0';
	else
	{
		while (n)
		{
			out[size-- - 1] = ft_abs((n % 10)) + '0';
			n /= 10;
		}
	}
}
