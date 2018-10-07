/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:40:26 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:40:28 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_or(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	size[3];
	int				value[3];
	int				bytes;

	if (inititate_wait(champ, arena, 5, "OR"))
		return ;
	champ->run = NO;
	pc++;
	ft_bzero(size, 3);
	decode(arena->arena[pc], size);
	set_correct_size(size, 3);
	pc++;
	value[0] = get_one_value(size[0], pc, arena->arena, champ);
	pc += size[0];
	value[1] = get_one_value(size[1], pc, arena->arena, champ);
	pc += size[1];
	value[2] = get_reg_index(size[2], pc, arena->arena);
	if (value[2] <= 0 || value[2] > (REG_NUMBER - 1))
		return ;
	champ->reg[value[2] - 1] = value[0] | value[1];
	champ->carry = champ->reg[value[2] - 1] == 0;
	bytes = 2 + (size[0] + size[1] + size[2]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	show_trace("\nOR instruction played by : ", arena, champ, SHOW_CHAMP);
}
