/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:57 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_internal.h"

void	ft_printf_putnchar(char c, int times, int fd)
{
	while (times--)
		write(fd, &c, 1);
}

int		idigits(intmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		udigits(uintmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		get_int_arg(va_list *lst)
{
	int		res;

	res = va_arg(*lst, int);
	return (res);
}
