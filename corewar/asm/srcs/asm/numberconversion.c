/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberconversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:54:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/05 09:42:46 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

uint8_t	bintodec(char *bin_no)
{
	uint8_t	nbr;
	int		byte;

	byte = 128;
	nbr = 0;
	while (byte)
	{
		if (*bin_no == '1')
			nbr += byte;
		bin_no++;
		byte /= 2;
	}
	return (nbr);
}
