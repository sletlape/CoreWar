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

void	write_hex(t_conv **conv, int i)
{
	int		n;
	uint8_t	*num;

	n = (*conv)->b_param[i];
	num = (void*)&(*conv)->param[i];
	while (--n >= 0)
	{
		ft_putstr("0x");
		if (num[n] < 16)
			small_hex(num[n]);
		else
			print_hex(num[n]);
		ft_putchar(' ');
	}
}

void	show_hex(t_conv *conv)
{
	int		i;

	ft_putstr("0x");
	if (conv->opcode < 16)
		small_hex(conv->opcode);
	else
		print_hex(conv->opcode);
	ft_putchar(' ');
	if (conv->hasencoding)
	{
		ft_putstr("0x");
		if (conv->encoding < 16)
			small_hex(conv->encoding);
		else
			print_hex(conv->encoding);
		ft_putchar(' ');
	}
	i = -1;
	while (++i < conv->n_params)
	{
		write_hex(&conv, i);
	}
	ft_putline();
}
