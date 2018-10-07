/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:32:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/23 11:15:24 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

static void	store_reg(t_champ *champ, int *value, int sum, t_arena *arena)
{
	champ->reg[value[2] - 1] = get_one_value(REG_SIZE,
			sum, arena->arena, champ);
	champ->carry = (champ->reg[value[2] - 1] == 0);
	show_trace("\nLDI played by : ", arena, champ, SHOW_CHAMP);
}

void		ft_ldi(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	size[3];
	int				value[3];
	int				start;
	int				sum;

	if (inititate_wait(champ, arena, 24, "LDI"))
		return ;
	champ->run = NO;
	start = pc;
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
	sum = value[0] + value[1];
	champ->pc = (champ->pc + size[0] + size[1] + size[2]) % MEM_SIZE;
	if (value[2] <= 0 || (value[2] > (REG_NUMBER - 1)))
		return ;
	store_reg(champ, value, start + sum, arena);
}
