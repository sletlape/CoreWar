/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:30:25 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:30:27 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_add(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	size[3];
	int				value[3];
	int				bytes;

	if (inititate_wait(champ, arena, 9, "ADD"))
		return ;
	champ->run = NO;
	pc++;
	ft_bzero(size, 3);
	decode(arena->arena[pc], size);
	pc++;
	value[0] = get_one_value(size[0], pc, arena->arena, champ);
	pc += size[0];
	value[1] = get_one_value(size[1], pc, arena->arena, champ);
	pc += size[1];
	value[2] = get_reg_index(size[2], pc, arena->arena);
	if (value[2] <= 0 || value[2] > (REG_NUMBER - 1))
		return ;
	champ->reg[value[2] - 1] = value[0] + value[1];
	champ->carry = (champ->reg[value[2] - 1] == 0);
	bytes = 2 + (size[0] + size[1] + size[2]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	show_trace("\nADD instruction : played by : ", arena, champ, SHOW_CHAMP);
}
