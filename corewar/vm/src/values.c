/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:11:45 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 12:12:42 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int			get_one_value(int size, int pos,
		unsigned char *arena, t_champ *champ)
{
	unsigned char	buf[T_LAB];
	int				num;

	ft_bzero(buf, T_LAB);
	access_data(arena, size, pos, buf);
	num = bytes_tonum(buf, size);
	if (size == T_REG)
		num = champ->reg[num - 1];
	return (num);
}

int			get_reg_index(int size, int pos, unsigned char *arena)
{
	unsigned char	buf[T_LAB];
	int				num;

	ft_bzero(buf, T_LAB);
	access_data(arena, size, pos, buf);
	num = bytes_tonum(buf, size);
	return (num);
}

void		convert_tobigendian(unsigned char *num)
{
	unsigned char temp[4];

	temp[0] = num[3];
	temp[1] = num[2];
	temp[2] = num[1];
	temp[3] = num[0];
	num[0] = temp[0];
	num[1] = temp[1];
	num[2] = temp[2];
	num[3] = temp[3];
}
