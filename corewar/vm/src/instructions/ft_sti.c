/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:43:08 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:52:35 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

static void	int_size(unsigned char *size)
{
	if (size[1] == REG_SIZE)
		size[1] = IND_SIZE;
	if (size[2] == REG_SIZE)
		size[2] = IND_SIZE;
}

void		ft_sti(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	*val;
	unsigned char	size[3];
	int				value[3];
	int				bytes;
	int				start;

	if (inititate_wait(champ, arena, 24, "STI"))
		return ;
	champ->run = NO;
	start = pc;
	ft_bzero(size, 3);
	decode(arena->arena[++pc], size);
	int_size(size);
	value[0] = get_one_value(size[0], ++pc, arena->arena, champ);
	pc += size[0];
	value[1] = get_one_value(size[1], pc, arena->arena, champ);
	pc += size[1];
	value[2] = get_one_value(size[2], pc, arena->arena, champ);
	bytes = 2 + (size[0] + size[1] + size[2]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	start = (start + ((value[1] + value[2]))) % MEM_SIZE;
	val = (unsigned char*)&value[0];
	convert_tobigendian(val);
	write_toarena(arena, val, start, DIR_SIZE);
	show_trace("\nAfter sti : played by : ", arena, champ, SHOW_ARENA);
}
