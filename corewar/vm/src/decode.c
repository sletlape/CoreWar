/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:53:17 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:58:34 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int			get_type_size(char type)
{
	if (type == REG_CODE)
		return (T_REG);
	else if (type == DIR_CODE)
		return (T_DIR);
	else if (type == IND_CODE)
		return (T_IND);
	return (0);
}

void		decode(unsigned char code, unsigned char *size)
{
	size[0] = code >> 6;
	size[1] = code << 2;
	size[1] = size[1] >> 6;
	size[2] = code << 4;
	size[2] = size[2] >> 6;
	size[0] = get_type_size(size[0]);
	size[1] = get_type_size(size[1]);
	size[2] = get_type_size(size[2]);
}
