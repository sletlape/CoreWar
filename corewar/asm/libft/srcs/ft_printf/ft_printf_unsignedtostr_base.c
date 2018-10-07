/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsignedtostr_base.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:54 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:55 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

void		unstostr_base(char *out, uintmax_t n, \
t_arg *arg, char *base)
{
	int		index;
	int		size;
	int		len;
	int		b;

	b = ft_strlen(base);
	len = udigits(n, b);
	size = ft_max(len, arg->precision);
	index = 0;
	while (index < size - len)
		out[index++] = '0';
	if (n == 0 && !(arg->prec_set && arg->precision == 0))
		out[index] = '0';
	else
	{
		while (n)
		{
			out[size-- - 1] = base[ft_abs((n % b))];
			n /= b;
		}
	}
}
