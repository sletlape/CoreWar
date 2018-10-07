/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:22:31 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:22:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"
#include "ft_printf_handler.h"

extern t_handler	g_table[];

int					ft_printf_handler(t_arg *arg, va_list *lst)
{
	int i;

	i = 0;
	while (g_table[i].conv != 0)
	{
		if (g_table[i].conv == arg->conversion)
			return (g_table[i].f(arg, lst));
		i++;
	}
	if (arg->conversion)
		ft_printf_noconv(arg, lst);
	return (0);
}
