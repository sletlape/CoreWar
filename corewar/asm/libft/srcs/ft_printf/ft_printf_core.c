/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:26 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:28 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static int	print_arg(char **str, va_list *lst, int fd)
{
	t_arg	arg;
	int		len;

	ft_bzero(&arg, sizeof(t_arg));
	arg.fd = fd;
	len = ft_printf_parse_arg(*str, &arg, lst);
	ft_printf_handler(&arg, lst);
	*str += len;
	return (arg.size);
}

int			ft_printf_core(int fd, const char *format, va_list *lst)
{
	char		*cursor;
	int			out;

	cursor = (char*)format;
	out = 0;
	while (*cursor)
	{
		if (*cursor == '%')
			out += print_arg(&cursor, lst, fd);
		else
		{
			ft_putchar_fd(*cursor++, fd);
			out++;
		}
	}
	return (out);
}
