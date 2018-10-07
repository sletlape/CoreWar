/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:39:36 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:42:05 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

static void	store_reg(t_champ *champ, int *value, int sum, t_arena *arena)
{
	champ->reg[value[2] - 1] = sum;
	champ->carry = (champ->reg[value[2] - 1] == 0);
	show_trace("\nLLDI played by : ", arena, champ, SHOW_CHAMP);
}

void		ft_lldi(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	size[3];
	int				value[3];
	int				bytes;
	int				start;
	int				sum;

	if (inititate_wait(champ, arena, 49, "LLDI"))
		return ;
	champ->run = NO;
	start = pc;
	ft_bzero(size, 3);
	decode(arena->arena[++pc], size);
	set_correct_size(size, 3);
	value[0] = get_one_value(size[0], ++pc, arena->arena, champ);
	pc += size[0];
	value[1] = get_one_value(size[1], pc, arena->arena, champ);
	pc += size[1];
	value[2] = get_reg_index(size[2], pc, arena->arena);
	sum = value[0] + value[1];
	sum = get_one_value(REG_SIZE, start + sum, arena->arena, champ);
	bytes = 2 + (size[0] + size[1] + size[2]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	if (value[2] <= 0 || (value[2] > (REG_NUMBER - 1)))
		return ;
	store_reg(champ, value, sum, arena);
}
