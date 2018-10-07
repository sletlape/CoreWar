/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:29 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:30 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		ret;
	va_list	lst;

	va_start(lst, format);
	ret = ft_printf_core(fd, format, &lst);
	va_end(lst);
	return (ret);
}
