/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:21 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:22 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	lst;

	va_start(lst, format);
	ret = ft_printf_core(1, format, &lst);
	va_end(lst);
	return (ret);
}
