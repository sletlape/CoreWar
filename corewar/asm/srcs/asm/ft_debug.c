/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 08:27:14 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/26 08:27:46 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	show_conv_before(char *line)
{
	ft_putstr(line);
	ft_putstr(" > ");
}

void	show_buffer_after(t_conv *line)
{
	ft_putstr("\t");
	ft_putstr(line->line);
	ft_putline();
}

void	small_hex(uint8_t octet)
{
	ft_putchar('0');
	if (octet < 10)
		ft_putchar(octet + '0');
	else
		ft_putchar(octet + 87);
}

void	print_hex(uint8_t octet)
{
	if (octet < 10)
		ft_putchar(octet + '0');
	else if (octet < 16)
		ft_putchar(octet + 87);
	else
	{
		print_hex(octet / 16);
		print_hex(octet % 16);
	}
}
