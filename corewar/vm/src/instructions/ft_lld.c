/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:39:06 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:39:15 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_lld(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	size[3];
	int				value[3];
	int				bytes;

	if (inititate_wait(champ, arena, 9, "LLD"))
		return ;
	champ->run = NO;
	pc++;
	ft_bzero(size, 3);
	decode(arena->arena[pc], size);
	set_correct_size(size, 2);
	pc++;
	value[0] = get_one_value(size[0], pc, arena->arena, champ);
	pc += size[0];
	value[1] = get_reg_index(size[1], pc, arena->arena);
	bytes = 2 + (size[0] + size[1]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	if (value[1] <= 0 || (value[1] > (REG_NUMBER - 1)))
		return ;
	champ->reg[value[1] - 1] = value[0];
	champ->carry = champ->reg[value[1] - 1] == 0;
	show_trace("\nLLD played by : ", arena, champ, SHOW_CHAMP);
}
